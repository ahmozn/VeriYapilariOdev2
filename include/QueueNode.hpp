/**
 * @file         QueueNode.hpp
 * @description  Queue düğümlerinin başlık dosyası. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         15.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "BSTNode.hpp"

class QueueNode{
    public:
        BSTNode* treeNode; //ağaç düğümü
        int level;         //ağaç düğümünün seviyesi
        QueueNode* next;   //sonraki düğüme pointer

        QueueNode(BSTNode* tNode);  //constructor
        ~QueueNode();          //destructor
};
#endif