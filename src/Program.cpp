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

    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<duration.count()<<" ms"<<endl; //okuma ekleme işlemi ne kadar sürdü
    fileAgaclar.close();    //agaclar.txt kapatıldı

    agaclar.agacyaz();
    agaclar.ekranaBas(0,10);
    agaclar.ekranaBas(11,100);


}