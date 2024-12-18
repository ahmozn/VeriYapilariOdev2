/**
 * @file         InnerNode.cpp
 * @description  Yaprakları seviyelerine göre tutan listenin iç düğümlerinin kaynak dosyası. Yaprakları tutar.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "InnerNode.hpp"

InnerNode::InnerNode(BSTNode* node): node(node), next(nullptr){}
InnerNode::~InnerNode(){}