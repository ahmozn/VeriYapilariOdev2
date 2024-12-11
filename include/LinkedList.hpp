#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedListNode.hpp"

class LinkedListNode;

class LinkedList{
    private: 
        LinkedListNode* head;
        LinkedListNode* last;
    public:
        LinkedList();   //constructor

        void agacEkle(const BST& bst, int satir); //listeye ağaç ekleme

        void agacyaz()const;
        void ekranaBas();

        ~LinkedList();  //destructor
};

#endif