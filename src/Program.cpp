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
            cout<<currentTree.height(currentTree.getRoot())<<endl;
            agaclar.agacEkle(currentTree,satir);
            satir++;
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
        system("CLS");
        agaclar.ekranaBas(startIndex,endIndex);
        agaclar.dugumGosterici(index);
        agaclar.agacCiz(index);
        cout<<"secim...: ";
        cin>>secim;
        switch (secim)
        {
        case 'a':
        case 'A':
            index--;
            if(startIndex>=10 && index==-1){
                startIndex-=10;
                endIndex=startIndex+10;
                index=endIndex-1;
            }
            if(index<0) index=0;
            break;
        
        case 'd':
        case 'D':
            index++;
            if(index>=endIndex){
                startIndex=endIndex;
                endIndex+=10;
                index=0;
            }
            else if(startIndex>0 && index>agaclar.agacSayisi()-11)  index--;
            else if(index>agaclar.agacSayisi()-1)                   index=agaclar.agacSayisi()-1;
            break;
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
        case 'w':
        case 'W':
            agaclar.tersCevir(startIndex+index);
            break;
        
        case 'q':
        case 'Q':
            cout<<"Cikis Secildi."<<endl;
            break;
        default:
            break;
        }
    } while (secim!='q' && secim!='Q');

    //desturctor cagrilari
}