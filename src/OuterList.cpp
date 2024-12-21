/**
 * @file         OuterList.cpp
 * @description  Yaprakları seviyelerine göre listelerde tutan listenin kaynak dosyası. İç içe liste olarak gerçeklenir.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "OuterList.hpp"
#include <iostream>

using namespace std;

//belirli bir seviyeye yaprak ekler
void OuterList::addLeaf(int level, BSTNode* node) {
    OuterNode* current = head;
    OuterNode* prev = nullptr;

    //seviye bulunur
    while (current != nullptr && current->level != level) {
        prev = current;
        current = current->next;
    }

    //yeni seviye oluşturulur
    if (current == nullptr) {
        current = new OuterNode(level);
        if (prev) prev->next = current;
        else head = current;
    }

    //eğer içerik varsa sona eklenir
    InnerNode* newNode = new InnerNode(node);
    if (current->innerListLast == nullptr) {
        current->innerListHead = newNode;  //liste boşsa yeni düğüm baş olur
    } else {
        current->innerListLast->next = newNode; 
    }
    current->innerListLast = newNode;
}

//yaprakların olduğu listeyi aynalama işlemi sonrası tersler
void OuterList::reverseInnerList(int level) {
    OuterNode* currentOuter = head;
    
    //belirtilen seviyeye gidilir
    while (currentOuter != nullptr && currentOuter->level != level) {
        currentOuter = currentOuter->next;
    }

    if (currentOuter != nullptr) {
        InnerNode* prev = nullptr;
        InnerNode* curr = currentOuter->innerListHead;
        InnerNode* next = nullptr;

        //iç listeyi ters çevirme
        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;        
            curr = next;        
        }

        //başı ve sonu değiştir
        currentOuter->innerListHead = prev;  
        currentOuter->innerListLast = curr;  
    }
}

OuterList::OuterList():head(nullptr), currentLevel(0){}
OuterList::~OuterList(){}