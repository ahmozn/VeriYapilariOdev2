#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedListNode.hpp"

class LinkedListNode;

class LinkedList{
    private: 
        LinkedListNode* head;
        LinkedListNode* last;
        void adres(int start, int end);
        void deger(int start, int end);
        void adresNext(int start, int end);
    public:
        LinkedList();   //constructor

        void agacEkle(const BST& bst, int satir); //listeye ağaç ekleme

        void agacyaz()const;
        void ekranaBas(int start, int end);

        ~LinkedList();  //destructor
};

#endif