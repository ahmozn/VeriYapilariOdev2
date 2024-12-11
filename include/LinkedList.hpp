#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedListNode.hpp"

class LinkedList{
    private: 
        LinkedListNode* head;
        LinkedListNode* last;
    public:
        LinkedList();   //constructor

        void agacEkle(const BST& bst); //listeye ağaç ekleme

        ~LinkedList();  //destructor
};

#endif