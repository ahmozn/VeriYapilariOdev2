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

class BSTNode;

class BST{
    private: 
        BSTNode* root;
        BSTNode* dugumEkle(BSTNode* node, char chr);

        void tyaz(BSTNode* node) const;
    public:
        void ekle(char chr);
        int toplam(BSTNode* root, bool isLeft=false);
        BSTNode* getRoot() const;

        void yazdir()const;
        int height(BSTNode* root);
        BST();   //constructor
        ~BST();  //destructor
};

#endif