#ifndef BSTNODE_HPP
#define BSTNODE_HPP

class BSTNode{  
    public:
        char data;      //veri
        BSTNode* left;  //sol alt düğüm
        BSTNode* right; //sağ alt düğüm
        
        BSTNode(char chr);   //constructor
        ~BSTNode();  //destructor
};

#endif