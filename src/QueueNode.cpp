/**
 * @file         QueueNode.cpp
 * @description  Queue düğümlerinin kaynak dosyası. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         15.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "QueueNode.hpp"

QueueNode::QueueNode(BSTNode* tNode): treeNode(tNode), level(0),next(nullptr){}
QueueNode::~QueueNode(){}