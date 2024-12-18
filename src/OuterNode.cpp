/**
 * @file         OuterNode.cpp
 * @description  Yaprakları seviyelerine göre tutan listenin düğümlerinin başlık dosyası. Ağacın seviyelerini ayırabilmeye yarar. 
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         18.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "OuterNode.hpp"

OuterNode::OuterNode(int level): level(level), innerListHead(nullptr), innerListLast(nullptr), next(nullptr){}
OuterNode::~OuterNode(){}