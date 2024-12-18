/**
 * @file         InnerNode.hpp
 * @description  Yaprakları seviyelerine göre tutan listenin iç düğümlerinin başlık dosyası. Yaprakları tutar.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef INNERNODE_HPP
#define INNERNODE_HPP

#include "BSTNode.hpp"

class InnerNode{
    public:
        BSTNode* node;
        InnerNode* next;

        InnerNode(BSTNode* node);  //constructor
        ~InnerNode();          //destructor
};
#endif