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

void LinkedList::adres(int start, int end){
    LinkedListNode* temp=head;
    if(start==0){
        temp=temp;
    }else{
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<((int)temp)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

void LinkedList::deger(int start, int end){
    LinkedListNode* temp=head;
    if(start==0){
        temp=temp;
    }else{
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<temp->tree.toplam(temp->tree.getRoot())<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

void LinkedList::adresNext(int start, int end){
    LinkedListNode* temp=head;
    if(start==0){
        temp=temp;
    }else{
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<=end){
        cout<<". "<<((int)temp->next)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

LinkedList::LinkedList():head(nullptr), last(nullptr){}

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

void LinkedList::ekranaBas(int start, int end){
    adres(start,end);
    deger(start,end);
    adresNext(start,end);

}

//destructor
LinkedList::~LinkedList(){}