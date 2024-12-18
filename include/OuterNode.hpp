/**
 * @file         OuterNode.hpp
 * @description  Yaprakları seviyelerine göre tutan listenin düğümlerinin başlık dosyası. Ağacın seviyelerini ayırabilmeye yarar. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef OUTERNODE_HPP
#define OUTERNODE_HPP

#include "InnerNode.hpp"

class OuterNode{
    public:
        int level;         
        InnerNode* innerListHead;
        InnerNode* innerListLast;
        OuterNode* next;   

        OuterNode(int level);  //constructor
        ~OuterNode();          //destructor
};
#endif