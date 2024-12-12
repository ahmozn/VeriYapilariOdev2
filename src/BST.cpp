/**
 * @file         BST.cpp
 * @description  BinarySearchTree yapısının bulunduğu kaynak dosyası. Programda kullanılacak olan
 *               bazı fonksiyonlar burada tanımlanmıştır.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "BST.hpp"
#include <iostream>

BST::BST():root(nullptr){}

//düğüm ekleme
BSTNode* BST::dugumEkle(BSTNode* node, char chr){
    if (node == nullptr) {
        return new BSTNode(chr);  //hiç düğüm yoksa yeni düğüm oluştur
    }
    if (chr < node->data) {
        node->left = dugumEkle(node->left, chr);   //sola ekle
    } else if (chr > node->data) {
        node->right = dugumEkle(node->right, chr); //sağa ekle
    }
    return node;
}

//public düğüm ekleme
void BST::ekle(char chr){
    root=dugumEkle(root,chr);
}

int BST::toplam(BSTNode* root, bool isLeft){
    if(root==nullptr){
        return 0;
    }

    int leftSum=toplam(root->left,true);
    int rightSum=toplam(root->right,false);

    int deger;
    if(isLeft){
        deger=root->data*2;
    }else{
        deger=root->data;
    }

    return leftSum+deger+rightSum;
}

BSTNode* BST::getRoot() const{
    return root;
}

void BST::tyaz(BSTNode* node) const{
    if (node != nullptr) {
        tyaz(node->left);
        std::cout << node->data << " ";
        tyaz(node->right);
    }
}

void BST::yazdir() const{
    tyaz(root);
    std::cout<<std::endl;
}

int BST::height(BSTNode* root){
    if (root == nullptr) {
        return 0; // Ağaç boşsa yüksekliği 0'dır
    }
    // Sol ve sağ alt ağaçların yüksekliklerini hesapla
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Daha büyük olanı al ve kök için 1 ekle
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

BST::~BST(){}