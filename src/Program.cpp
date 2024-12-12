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
#include <chrono>

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

    system("CLS");

    auto start=chrono::high_resolution_clock::now(); //okuma ekleme süresi hesaplayici
    cout<<"agaclar.txt okunuyor..."<<endl;


    char ch;
    int satir=0;
    BST currentTree;
    while(fileAgaclar.get(ch)){
        if(ch=='\n'){
            satir++;
            cout<<currentTree.height(currentTree.getRoot())<<endl;
            agaclar.agacEkle(currentTree,satir);
            currentTree=BST();
        }
        else{
            currentTree.ekle(ch);
        }
    }
    if (currentTree.getRoot() != nullptr) {
        agaclar.agacEkle(currentTree,satir);
    }

    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<duration.count()<<" ms"<<endl; //okuma ekleme işlemi ne kadar sürdü
    fileAgaclar.close();    //agaclar.txt kapatıldı

    agaclar.agacyaz();

    char secim;
    do
    {
        agaclar.ekranaBas(startIndex,endIndex);
        agaclar.dugumGosterici(index);
        cout<<"secim...: ";
        cin>>secim;
        cout<<endl;
        cout<<index<<endl;
        switch (secim)
        {
        case 'a':
        case 'A':
            cout<<"a veya A basildi"<<endl;
            index--;
            if(startIndex>10 && index==-1){
                startIndex-=11;
                endIndex=startIndex+10;
                index=endIndex-1;
            }
            if(index<0) index=0;
            break;
        
        case 'd':
        case 'D':
            cout<<"d veya D basildi"<<endl;
            index++;
            if(index>=endIndex){
                startIndex=endIndex+1;
                endIndex+=10;
                index=0;
            }
            else if(startIndex>0 && index>agaclar.agacSayisi()-11)  index--;
            else if(index>agaclar.agacSayisi()-1)                   index=agaclar.agacSayisi()-1;
            break;
        
        case 'w':
        case 'W':
            cout<<"w veya W basildi"<<endl;
            break;
        
        case 'q':
        case 'Q':
            cout<<"q veya Q basildi"<<endl;
            cout<<"Cikis Secildi."<<endl;
            break;
        default:
            break;
        }
    } while (secim!='q' && secim!='Q');
    
}