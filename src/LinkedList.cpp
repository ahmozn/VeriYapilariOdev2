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
    
    if(temp==nullptr) return;

    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;

    while(temp!=nullptr && temp->index>=start && temp->index<end){
        cout<<". "<<((int)temp)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//liste yazdırmada ağaç değerlerini yazdırır
void LinkedList::deger(int start, int end){
    LinkedListNode* temp=head;
    
    if(temp==nullptr) return;
    
    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<end){
        cout<<". "<<temp->tree.toplam(temp->tree.getRoot())<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//liste yazdırmada sonraki düğüm adreslerini yazdırır
void LinkedList::adresNext(int start, int end){
    LinkedListNode* temp=head;
    
    if(temp==nullptr) return;

    if(start<0) start=0;

    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    while(temp!=nullptr && temp->index>=start && temp->index<end){
        cout<<". "<<((int)temp->next)%10000<<"\t.\t";
        temp=temp->next;
    }
    cout<<endl;

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;
}

//--------------------------PUBLIC--------------------------

//constructor
LinkedList::LinkedList():head(nullptr), last(nullptr){}

//atıl
LinkedListNode* LinkedList::agacbul(int index){
    LinkedListNode* temp=head;
    if(temp==nullptr){
        return temp;//değişecek
    }
    while(temp!=nullptr && temp->index!=index){
        temp=temp->next;
    }
    cout<<"bulunan dugum"<<temp<<endl;
    return temp;
}

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

//listeden ağaç siler
void LinkedList::agacSil(int index){
    if(head==nullptr||index<0){
        cout<<"gecersiz islem - LList.agacSil()"<<endl;
        return;
    }

    LinkedListNode* temp=head;
    LinkedListNode* prev=nullptr;
    
    if(index==0){
        int ix=0;
        head=head->next;
        delete temp;
        if(head==nullptr) last=nullptr;

        LinkedListNode* tmp=head;
        while(tmp!=nullptr){
            prev=tmp;
            tmp->index=ix;
            tmp=tmp->next;
            ix++;
        }
        last=prev;
        return;
    }

    for(int i=0; temp!=nullptr && i<index; i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==nullptr) return;

    prev->next=temp->next;
    if(temp->next==nullptr) last=prev;

    delete temp;

    LinkedListNode* curr=prev->next;
    if(curr==nullptr) return;
    int ix=prev->index+1;
    cout<<prev->index;
    while(curr!=nullptr){
        curr->index=ix;
        curr=curr->next;
        ix++;
    }
    cout<<"son agac adresi: "<<last<<endl;
}

//listedeki toplam ağaç sayısını döndürür
int LinkedList::agacSayisi(){
    int toplam=0;
    LinkedListNode* temp=last;
    if(temp==nullptr){
        cout<<"agac yok - agacSayisi()"<<endl;
        return -1;
    }
    return (temp->index)+1;
}

//listedeki ağaçları çizer
void LinkedList::agacCiz(int index){
    LinkedListNode* temp=head;
    if(head==nullptr||index<0) return;

    for(int i=0; temp!=nullptr && i<index; i++){
        temp=temp->next;
    }
    temp->tree.ciz();
}

void LinkedList::tersCevir(int index){
    LinkedListNode* temp= head;
    if(temp==nullptr||index<0){
        return;
    }
    while (temp!=nullptr && temp->index!=index)
    {
        temp=temp->next;
    }
    temp->tree.aynala();
}

//atıl
void LinkedList::agacyaz()const {
    LinkedListNode* temp = head;
    int treeCount = 1;
    while (temp != nullptr) {
        cout << "Tree " << temp->index << ": ";
        temp->tree.yazdir();
        temp = temp->next;
        treeCount++;
    }
}

//listeyi ekrana yazar, belirtilen index aralığını kullanır
void LinkedList::ekranaBas(int start=0, int end=10){
    adres(start,end);
    deger(start,end);
    adresNext(start,end);
    //ağaç yazdırma fonk eklenecek
}

//listede bulunulan düğümü gösterir
void LinkedList::dugumGosterici(int index=0){
    if(agacSayisi()<=0){
        return;
    }
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