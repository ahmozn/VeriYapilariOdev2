#include "LinkedList.hpp"
#include <iostream>

using namespace std;

void LinkedList::adres(){
    LinkedListNode* temp=head;
    
    for(int i=0; i<last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;

    while(temp!=nullptr){
        cout<<". "<<((int)temp)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=0; i<last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

void LinkedList::deger(){
    LinkedListNode* temp=head;

    while(temp!=nullptr){
        cout<<". "<<temp->tree.toplam(temp->tree.getRoot())<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=0; i<last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

void LinkedList::adresNext(){
    LinkedListNode* temp=head;

    while(temp!=nullptr){
        cout<<". "<<((int)temp->next)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=0; i<last->index;i++){
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

void LinkedList::ekranaBas(){
    adres();
    //--------------------------------------------------------------------
    deger();
    //--------------------------------------------------------------------
    adresNext();
}

//destructor
LinkedList::~LinkedList(){}