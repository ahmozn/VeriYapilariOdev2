/**
 * @file         BSTNode.hpp
 * @description  BinarySearchTree düğümlerinin başlık dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
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