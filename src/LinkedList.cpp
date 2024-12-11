#include "LinkedList.hpp"

LinkedList::LinkedList():head(nullptr), last(nullptr){}

void LinkedList::agacEkle(const BST& bst){
    LinkedListNode* newNode= new LinkedListNode();
    newNode->tree=bst;
    if(head==nullptr){
        head=newNode;
        last=newNode;
    }else{
        last->next=newNode;
        last=newNode;
    }
}

LinkedList::~LinkedList(){}