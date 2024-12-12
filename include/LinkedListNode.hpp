/**
 * @file         LinkedListNode.hpp
 * @description  LinkedList düğümlerinin başlık dosyası. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

#include "BST.hpp"

class LinkedListNode{
    public:
        int index;
        BST tree;
        LinkedListNode* next;
        LinkedListNode(int index);
        ~LinkedListNode();
};

#endif