/**
 * @file         LinkedList.hpp
 * @description  LinkedList yapısının başlık dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
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

        LinkedListNode* agacbul(int index);//atıl
        void agacEkle(const BST& bst, int satir); //listeye ağaç ekleme
        void agacSil(int index);
        int agacSayisi(); //toplam ağaç sayısı

        void agacCiz(int index);
        void tersCevir(int index);
        void agacyaz()const;
        void ekranaBas(int start, int end);
        void dugumGosterici(int index);

        ~LinkedList();  //destructor
};

#endif