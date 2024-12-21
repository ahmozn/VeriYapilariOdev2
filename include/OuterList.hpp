/**
 * @file         OuterList.hpp
 * @description  Yaprakları seviyelerine göre listelerde tutan listenin başlık dosyası. İç içe liste olarak gerçeklenir.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#ifndef OUTERLIST_HPP
#define OUTERLIST_HPP

#include "OuterNode.hpp"


class OuterList{
    public:
        int currentLevel; 
        OuterNode* head;   //seviyeleri tutan düğümün başı

        void addLeaf(int level, BSTNode* node); //yaprakları iç listeye ekler
        void reverseInnerList(int level);       //yaprakların olduğu listeyi ters çevirir

        OuterList();  //constructor
        ~OuterList(); //destructor
};
#endif