//
//  Array.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/15/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <assert.h>
#include "Node.hpp"

template <class Type>
class Array
{
private:
    Node<Type>* front;
    int size;
public:
    Array<Type>(int size);
    int getSize();
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};

//Implementation section of the templated class!
 
/*
 Creates an Array of specified size by linking Node<Type> together.
*/
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0)
    this->size = size;
    
    this->front = new Node<Type>();
    /*
     Starting at one because head already points to a vaild Node.
     */
    for(int index = 1; index < size; index ++)
    {
        Node<Type>* currentNode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0) && index < size);
    int value = 0;
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
}

template <class Type>
int Array<Type> :: getSize()
{
    return size;
}

#endif /* Array_h */
