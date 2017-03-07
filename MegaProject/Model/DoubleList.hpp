//
//  DoubleList.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 3/3/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
    
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

template <class Type>
void DoubleList<Type> :: add(Type data)
{
    
}

template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    
}

template <class Type>
void DoubleList<Type> :: addAtIndexFast(int index, Type value)
{
    
}

template <class Type>
void DoubleList<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(index == 0)
    {
        addFront(value);
    }
    else if (size == index)
    {
        addEnd(value);
    }
    else
    {
        BiDirectionalNode<Type> * insertedNode = new BiDirectionalNode<Type>(value);
        BiDirectionalNode<Type> * current = front;
        BiDirectionalNode<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
        
        size++;
}

template <class Type>
Type DoubleList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type information;
    BiDirectionalNode<Type> * current = front;
    for (int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    information = current->getNodeData();
    return information;
    
    
}

template <class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() /2)
    {
        reference = this->getFront();
        for(int position = 0; posiiton < index; position++)
        {
            reference = reference ->getPreviousPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this-getSize() - 1; position > index; position --)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}


#endif /* DoubleList_h */
