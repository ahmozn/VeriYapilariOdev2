/**
 * @file         LevelNode.hpp
 * @description  Yaprakları seviyelerine göre tutan listenin düğümlerinin başlık dosyası. Ağacın seviyelerini ayırabilmeye yarar. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef LEVELNODE_HPP
#define LEVELNODE_HPP

#include "InnerNode.hpp"

class LevelNode{
    public:
        int level;                  //seviye bilgisi
        InnerNode* innerListHead;   //iç liste başı
        InnerNode* innerListLast;   //iç liste sonu
        LevelNode* next;            //sonraki seviye düğümü

        LevelNode(int level);  //constructor
        ~LevelNode();          //destructor
};
#endif