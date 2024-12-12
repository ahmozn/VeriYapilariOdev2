/**
 * @file         BSTNode.cpp
 * @description  BinarySearchTree düğümlerinin kaynak dosyası.
 * @course       2. Öğretim A grubu
 * @assignment   2024-2025 Güz, 2. Ödev
 * @date         11.12.2024
 * @author       Ahmet Özhan ÖZEN   ozhan.ozen@ogr.sakarya.edu.tr
 */
#include "BSTNode.hpp"

BSTNode::BSTNode(char chr): data(chr), left(nullptr), right(nullptr){}
BSTNode::~BSTNode(){}