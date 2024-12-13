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

//--------------------------PRIVATE--------------------------

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

void BST::ayna(BSTNode* root){
    if (root == nullptr) {
        return;
    }

    // Sol ve sağ alt ağaçları yer değiştir
    BSTNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Sol ve sağ alt ağaçları aynala
    ayna(root->left);
    ayna(root->right);
}


void BST::agacSil(BSTNode* node){
    if(node==nullptr) return;

    agacSil(node->left);
    agacSil(node->right);

    delete node;
    node=nullptr;
}

void BST::agacCiz(BSTNode* root, int level, int space){
    if(root==nullptr) return;

    agacCiz(root->right, level+1, space+5);

    if(level>0) std::cout<<space<<' ';
    std::cout<<root->data<<std::endl;

    agacCiz(root->left, level+1, space+5);
}
//--------------------------PUBLIC--------------------------

//public düğüm ekleme
void BST::ekle(char chr){
    root=dugumEkle(root,chr);
}

void BST::aynala(){
    ayna(root);
}

void BST::ciz(int level, int space){
    agacCiz(root,level,space);
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

BST::~BST(){
    agacSil(root);
}