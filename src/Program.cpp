/**
 * @file         Program.cpp
 * @description  Verilen agaclar.txt dosyasını tarar, her satırda ağaç oluşturur. Satırdaki karakterleri ilgili ağaca ekler.
 *               Liste üzerinde A ve D tuşları ile gezilebilir, bulunulan düğümdeki ağaç gösterilir. İlgili düğümü silme,
 *               düğümdeki ağacı aynalama gibi işlemleri gerçekleştirir.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "BST.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    LinkedList agaclar;
    int startIndex=0;
    int endIndex=10;
    int index=0;

    ifstream fileAgaclar("agaclar.txt");
    if(!fileAgaclar){
        cerr<<"Dosya acilamadi"<<endl;
        return 1;
    }

    char ch;
    int satir=0;
    BST currentTree;
    while(fileAgaclar.get(ch)){ //agaclar.txt'den karakter karakter okuyarak ağaç oluşturma
        if(ch=='\n'){
            cout<<currentTree.height(currentTree.getRoot())<<endl;
            agaclar.agacEkle(currentTree,satir);
            satir++;
            currentTree=BST();
        }
        else{
            currentTree.ekle(ch);
        }
    }
    if (currentTree.getRoot() != nullptr) { //son ağaç da eklenir
        agaclar.agacEkle(currentTree,satir);
    }
    fileAgaclar.close();    //agaclar.txt kapatıldı

    char secim;
    do
    {
        system("CLS");
        agaclar.ekranaBas(startIndex,endIndex);
        agaclar.dugumGosterici(index);
        agaclar.agacCiz(startIndex+index);
        cout<<"secim...: ";
        cin>>secim;
        switch (secim)
        {
        //küçük veya büyük a basıldığında sola kayar
        case 'a':
        case 'A':
            index--;
            if(startIndex>=10 && index==-1){
                startIndex-=10;
                endIndex=startIndex+10;
                index=endIndex-startIndex-1;
            }
            if(index<0) index=0;
            break;
        //küçük veya büyük d basıldığında sola kayar
        case 'd':
        case 'D':
            index++;
            if(startIndex+index>=endIndex){
                startIndex=endIndex;
                endIndex+=10;
                index=0;
            }
            else if(startIndex>0 && index>agaclar.agacSayisi()-startIndex-1)  index--;
            else if(index>agaclar.agacSayisi()-1)                   index=agaclar.agacSayisi()-1;
            break;
        //küçük veya büyük s basıldığında bulunulan ağacı siler
        case 's':
        case 'S':
            agaclar.agacSil(startIndex+index);
            index--;
            if(startIndex>=10 && index==-1){
                startIndex-=10;
                endIndex=startIndex+10;
                index=endIndex-1;
            }
            if(index<0) index=0;
            break;
        //küçük veya büyük w basıldığında bulunulan ağacı aynalar
        case 'w':
        case 'W':
            agaclar.tersCevir(startIndex+index);
            break;
        //küçük veya büyük q basıldığında programdan çıkar
        case 'q':
        case 'Q':
            cout<<"Cikis Secildi."<<endl;
            break;
        default:
            break;
        }
    } while (secim!='q' && secim!='Q');

    return 0;
}