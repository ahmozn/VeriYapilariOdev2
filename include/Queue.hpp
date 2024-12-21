/**
 * @file         Queue.hpp
 * @description  Queue yapısının başlık dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         15.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"

class BSTNode;

class Queue{
    private:
        QueueNode* frontNode;   //kuyruk önündeki düğüm
        QueueNode* rearNode;    //kuyruk sonundaki düğüm
        int count;
    public:
        void enqueue(BSTNode* tNode);  //eleman ekleme
        void dequeue();                         //eleman çıkarma
        BSTNode* frontNodeValue();              //ön elemanı alma
        int frontLevel();                       //ön elemanın level'ını alma
        bool empty();                           //boş dolu kontrolü
        int size();

        QueueNode* getFirst();

        Queue();
        ~Queue();
};

#endif