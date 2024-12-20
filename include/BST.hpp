/**
 * @file         BST.hpp
 * @description  BinarySearchTree yapısının bulunduğu başlık dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include "Queue.hpp"
#include "OuterList.hpp"

class BSTNode;

class BST{
    private: 
        BSTNode* root;    //kök düğüm      
        OuterList* levels; 

        BSTNode* dugumEkle(BSTNode* node, char chr, int level);    //düğüm eklemek için private fonksiyon
        void ayna(BSTNode* root);                       //aynalamak için private fonksiyon
        void agacSil(BSTNode* node);                    //silmek için private fonksiyon
        void agacCiz(BSTNode* root, int level=0, int space=0);  //güncellenecek

        void tyaz(BSTNode* node) const; //atıl
    public:
        BSTNode* ekle(char chr);                            //düğüm ekle public
        void aynala();                                  //aynala public
        void ciz(int level=0, int space=0);             //güncellenecek
        int toplam(BSTNode* root, bool isLeft=false);   //ağaç değerini döndürür
        BSTNode* getRoot() const;                       //ağaç kök düğümünü döndürür

        void yazdir()const;//atıl
        int height(BSTNode* root);                      //ağacın yüksekliğini döndürür
        
        void treeprint();
        int printlv(int n);
        void displv(BSTNode* p, int lv, int d);

        void doldur(BSTNode* root, char chr);
        void doldurLevel(BSTNode* root, int level, char chr);
        void doldurAll(BSTNode* root, char chr);
        void yaz();

        Queue* lot(BSTNode* root);
        OuterList* getLevelsList();
        void updateLevels(BSTNode* root, OuterList* outerlist, int level);


        BST();   //constructor
        ~BST();  //destructor
};

#endif