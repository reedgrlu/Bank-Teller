/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: March 2, 2019
 * Author: Reed Lu
 */
 
#pragma once

#include <cstdio>  // Needed for NULL

using namespace std;


template <class T>
class Node {
    public:
        T data;
        Node * next;
}; // Node