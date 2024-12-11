#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

#include "BST.hpp"

class LinkedListNode{
    public:
        int index;
        BST tree;
        LinkedListNode* next;
        LinkedListNode(int index);
        ~LinkedListNode();
};

#endif