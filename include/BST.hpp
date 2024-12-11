#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

class BST{
    private: 
        BSTNode* root;
        BSTNode* dugumEkle(BSTNode* node, char chr);
    public:
        void ekle(char chr);
        BSTNode* getRoot() const;
        BST();   //constructor
        ~BST();  //destructor
};

#endif