#include "BST.hpp"

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

BST::~BST(){}