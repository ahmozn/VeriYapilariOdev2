#include "LinkedList.hpp"
#include <iostream>

using namespace std;

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
    LinkedListNode* temp=head;
    for(int i=0; i<=last->index;i++){
        cout<<"........\t";
    }
    cout<<endl;
    while(temp!=nullptr){
        cout<<".  "<<&temp<<" .\t";
        temp=temp->next;
    }
    cout<<endl;
}

//destructor
LinkedList::~LinkedList(){}