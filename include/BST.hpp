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
        BSTNode* getRoot() const;

        void yazdir()const;
        int height(BSTNode* root);
        BST();   //constructor
        ~BST();  //destructor
};

#endif