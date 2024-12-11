#include "BST.hpp"
#include <iostream>

BST::BST():root(nullptr){}

//düğüm ekleme
BSTNode* BST::dugumEkle(BSTNode* node, char chr){
    if (node == nullptr) {
        return new BSTNode(chr);  //düğüm yoksa yeni düğüm oluştur
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