/**
 * @file         LinkedList.cpp
 * @description  LinkedList yapısının bulunduğu kaynak dosyası. Programda kullanılacak olan
 *               fonksiyonların çoğu burada bulunmaktadır.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "LinkedList.hpp"
#include <iostream>

using namespace std;

//--------------------------PRIVATE--------------------------

//liste yazdırırmada adresleri yazdırır
void LinkedList::adres(int start, int end){
    LinkedListNode* temp=head;
    
    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    for(int i=start; i<end && i<=last->index+1;i++){
        cout<<".........\t";
    }
    cout<<endl;

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<((int)temp)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index+1;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//liste yazdırmada ağaç değerlerini yazdırır
void LinkedList::deger(int start, int end){
    LinkedListNode* temp=head;
    
    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<temp->tree.toplam(temp->tree.getRoot())<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index+1;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//liste yazdırmada sonraki düğüm adreslerini yazdırır
void LinkedList::adresNext(int start, int end){
    LinkedListNode* temp=head;
    
    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<((int)temp->next)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index+1;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//--------------------------PUBLIC--------------------------

//constructor
LinkedList::LinkedList():head(nullptr), last(nullptr){}

//listeye ağaç ekler
void LinkedList::agacEkle(const BST& bst, int satir){
    LinkedListNode* newNode= new LinkedListNode(satir);
    newNode->tree=bst;
    if(head==nullptr){
        head=newNode;
        last=newNode;
    }else{
        last->next=newNode;
        last=newNode;
    }
}

//listedeki toplam ağaç sayısını döndürür
int LinkedList::agacSayisi(){
    int toplam=0;
    LinkedListNode* temp=last;
    if(temp==nullptr){
        cout<<"ağaç yok - agacSayisi()"<<endl;
        return -1;
    }
    return (temp->index)+1;
}

//atıl
void LinkedList::agacyaz()const {
    LinkedListNode* temp = head;
    int treeCount = 1;
    while (temp != nullptr) {
        cout << "Tree " << treeCount << ": ";
        temp->tree.yazdir();
        temp = temp->next;
        treeCount++;
    }
}

//listeyi ekrana yazar, belirtilen index aralığını kullanır
void LinkedList::ekranaBas(int start, int end){
    adres(start,end);
    deger(start,end);
    adresNext(start,end);

}

//listede bulunulan düğümü gösterir
void LinkedList::dugumGosterici(int index){
    for(int i=0;i<index;i++){
        cout<<"                ";
    }
    cout<<"^^^^^^^^^"<<endl;
    for(int i=0;i<index;i++){
        cout<<"                ";
    }
    cout<<"|||||||||"<<endl;
}

//destructor
LinkedList::~LinkedList(){}