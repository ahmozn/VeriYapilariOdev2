/**
 * @file         Queue.cpp
 * @description  Queue yapısının bulunduğu kaynak dosyası. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         15.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */

#include "Queue.hpp"
#include <iostream>

void Queue::enqueue(BSTNode* tNode){
    QueueNode* newNode = new QueueNode(tNode);
    if (rearNode == NULL) { //kuyruk boşsa
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void Queue::dequeue(){
    if (frontNode == nullptr) {
        return;
    }
    QueueNode* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode == nullptr) {
        rearNode = nullptr; //kuyruk boşaldığında rear güncellenir
    }
    delete temp;
}

BSTNode* Queue::frontNodeValue(){
    if (frontNode == NULL) {
        return nullptr;
    }
    return frontNode->treeNode;
}

int Queue::frontLevel(){
    if (frontNode == NULL) {
        return -1;
    }
    return frontNode->level;
}

QueueNode* Queue::getFirst(){
    return frontNode;
}

bool Queue::empty(){
    return frontNode==nullptr;
}

Queue::Queue():frontNode(nullptr), rearNode(nullptr){}
Queue::~Queue(){}