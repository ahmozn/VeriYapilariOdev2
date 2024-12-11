#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

#include "BST.hpp"

class LinkedListNode{
    public:
        BST tree;
        LinkedListNode* next;
        LinkedListNode();
        ~LinkedListNode();
};

#endif