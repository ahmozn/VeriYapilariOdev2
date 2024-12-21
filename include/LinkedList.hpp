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
        LinkedListNode* head;               //liste başı
        LinkedListNode* last;               //liste sonu
        void adres(int start, int end);     //düğümlerin adres değerlerini yazdıran private fonksiyon
        void deger(int start, int end);     //ağaç değerlerini yazdıran private fonksiyon
        void adresNext(int start, int end); //düğümlerin sonraki düğümü gösteren pointerlarını yazdıran private fonksiyon
    public:
        LinkedListNode* agacbul(int index);//atıl
        void agacEkle(const BST& bst, int satir); //listeye ağaç ekleme
        void agacSil(int index);                  //listeden ağaç silme
        int agacSayisi();                         //toplam ağaç sayısı

        void agacCiz(int index);                  //ilgili ağacı çizer
        void tersCevir(int index);                //düğümdeki ağacı ters çevirir
        void ekranaBas(int start, int end);       //listeyi ekrana basar
        void dugumGosterici(int index);           //bulunulan düğümü parmakla gösterir

        LinkedList();   //constructor
        ~LinkedList();  //destructor
};

#endif