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

InnerNode* OuterList::addInnerListNode(InnerNode* head, BSTNode* node){
    InnerNode* newNode=new InnerNode(node);
    if(OuterList::head==nullptr){
        
    }
}

InnerNode* OuterList::addInnerNode(InnerNode* head, BSTNode* node) {
        InnerNode* newNode = new InnerNode(node);
        newNode->next = head;
        return newNode;
    }

// Belirli bir seviyeye yaprak ekle
    void OuterList::addLeaf(int level, BSTNode* node) {
        OuterNode* current = head;
        OuterNode* prev = nullptr;

        // Seviyeyi bul veya oluştur
        while (current != nullptr && current->level != level) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            // Yeni seviye oluştur
            current = new OuterNode(level);
            if (prev) prev->next = current;
            else head = current;
        }

        // Eğer içerik varsa son düğümü bul ve ekle
        InnerNode* newNode = new InnerNode(node);
        if (current->innerListLast == nullptr) {
            current->innerListHead = newNode;  // Liste boşsa yeni düğüm baş olur
        } else {
            current->innerListLast->next = newNode;  // Son düğümün next'ine ekle
        }
        current->innerListLast = newNode;


        // İç listeye eleman ekle
        //current->innerListHead = addInnerNode(current->innerListHead, node);
    }

    // Seviyeleri yazdır
    void OuterList::print() {
        OuterNode* currentOuter = head;
        while (currentOuter) {
            cout << "Seviye " << currentOuter->level << ": ";
            InnerNode* currentInner = currentOuter->innerListHead;
            while (currentInner) {
                cout << currentInner->node->data << " ";
                currentInner = currentInner->next;
            }
            cout << endl;
            currentOuter = currentOuter->next;
        }
    }

OuterList::OuterList():head(nullptr), currentLevel(0){}
OuterList::~OuterList(){}