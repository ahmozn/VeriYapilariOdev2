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

    //başlangıc indexi 0dan farklıysa(ör: 10) ilgili düğüme gider
    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    for(int i=start; i<end && i<=last->index;i++){
        cout<<".........\t";
    }
    cout<<endl;

    //adresi 4 basamaklı gösterir
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

    //başlangıc indexi 0dan farklıysa(ör: 10) ilgili düğüme gider
    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    //BST sınıfındaki fonksiyon ile ağacın değerini gösterir, 4 basamak göstermesi için %10000 işlemi yapıldı
    while(temp!=nullptr && temp->index>=start && temp->index<end){
        cout<<". "<<temp->tree.toplam(temp->tree.getRoot())%10000<<"\t.\t";
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

    //başlangıc indexi 0dan farklıysa(ör: 10) ilgili düğüme gider
    if(start!=0){
        while(temp!=nullptr && temp->index!=start){
            temp=temp->next;
        }
    }

    //adresi 4 basamaklı gösterir
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
    
    //liste boşsa
    if(head==nullptr){
        head=newNode;
        last=newNode;
    }
    //eleman varsa sona ekle
    else{ 
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
    
    //listenin ilk elemanıysa
    if(index==0){
        int ix=0;
        head=head->next;
        delete temp;
        if(head==nullptr) last=nullptr;

        //ilk eleman silindikten sonra diğerlerinin indexleri değiştirilir
        LinkedListNode* tmp=head;
        while(tmp!=nullptr){
            prev=tmp;
            tmp->index=ix;
            tmp=tmp->next;
            ix++;
        }
        last=prev; //tmp'nin son değeri nullptr olduğundan last değişkenine prev değişkeni atanır
        return;
    }

    //index sıfırdan farklıysa ilgili düğüme gidilir
    for(int i=0; temp!=nullptr && i<index; i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==nullptr) return;

    prev->next=temp->next; //ilgili düğümden önceki düğümün sonraki düğüme bağlantısı yapılır
    if(temp->next==nullptr) last=prev; //eğer son düğüm silinecekse son düğümü tutan pointer güncellenir

    delete temp;

    //düğüm silindikten sonra, silinen düğümden sonraki düğümlerin indexi değiştirilir
    LinkedListNode* curr=prev->next;
    if(curr==nullptr) return;
    int ix=prev->index+1;
    cout<<prev->index;
    while(curr!=nullptr){
        curr->index=ix;
        curr=curr->next;
        ix++;
    }
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
    temp->tree.treeprint();
}

//ağacı ters çevirme fonksiyonu
void LinkedList::tersCevir(int index){
    LinkedListNode* temp= head;
    //liste boşsa veya index sıfırdan küçükse işleme alınmaz
    if(temp==nullptr||index<0){
        return;
    }
    //ilgili indexe sahip düğüme gidilir
    while (temp!=nullptr && temp->index!=index)
    {
        temp=temp->next;
    }
    temp->tree.aynala(); //BST sınıfının fonksiyonu çağrılır
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

//constructor
LinkedList::LinkedList():head(nullptr), last(nullptr){}
//destructor
LinkedList::~LinkedList(){}