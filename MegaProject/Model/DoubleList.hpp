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
    void addFront(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
    int indexOf(Type itemToFind);
    int nextIndexOf(Type item, int startingPoint);
    
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
void DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
        this->setEnd(addedNode);
    }
    else
    {
        this->getEnd()->setNextPointer(addedNode);
        addedNode->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addedNode);
    this->setSize(this->getSize() + 1);
}

template <class Type>
void DoubleList<Type> :: addFront(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
        this->setEnd(addedNode);
    }
    else
    {
        this->getFront()->setPreviousPointer(addedNode);
        addedNode->setNextPointer(this->getEnd());
    }
    this->setFront(addedNode);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    for(int spot =0; spot< index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp = nodeToTakeOut->getNodeData();
    
    BiDirectionalNode<Type> * prev = nodeToTakeOut->getPreviousPointer();
    BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();
    
    prev->setNextPointer(next);
    next->setPreviousPointer(prev);
    
    delete nodeToTakeOut;
    this->setSize(this->getSize() - 1);
    return derp;
    
}

template <class Type>
void DoubleList<Type> :: addAtIndexFast(int index, Type value)
{
    //Not finished
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() /2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference ->getPreviousPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    
}

template <class Type>
void DoubleList<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= this->getSize());
    if(index == 0)
    {
        addFront(value);
    }
    else if (this->getSize() == index)
    {
        add(value);
    }
    else
    {
        BiDirectionalNode<Type> * insertedNode = new BiDirectionalNode<Type>(value);
        BiDirectionalNode<Type> * current = this->getFront();
        BiDirectionalNode<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
        insertedNode->setPreviousPointer(previous);
        current->setPreviousPointer(insertedNode);
        
        this->setSize(this->getSize() + 1);
    }
}

template <class Type>
Type DoubleList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type information;
    BiDirectionalNode<Type> * current = this->getFront();
    for (int position = 0; position < index; position++)
    {
        current = current->getNextPointer();
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
        for(int position = 0; position < index; position++)
        {
            reference = reference ->getPreviousPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}

//Loop over structure
//Compare Node's data to parameter
//If they match, return index to count of loop
//Else continue
//return invalid/not in list

template <class Type>
int DoubleList<Type> :: indexOf(Type findMe)
{
    int index = -1;
    
    BiDirectionalNode<Type> * searchPointer = this->getFront();
    
    for (int spot = 0; spot < this->getSize(); spot++)
    {
        if(findMe == searchPointer->getNodeData())
        {
            return spot;
        }
        searchPointer = searchPointer->getNextPointer();
    }
    
    return index;
}

template <class Type>
int  DoubleList<Type> :: nextIndexOf(Type value, int position)
{
    assert(position >= 0 && position < this->getSize());
    
    int nextIndex = -1;
    
    BiDirectionalNode<Type> * current = this->getFront();
    
    for (int index = 0; index < this->getSize(); index ++)
    {
        if(index >= position)
        {
            if(current->getNodeData() == value)
            {
                return index;
            }
        }
        current = current->getNextPointer();
    }
    
    return nextIndex;
}


#endif /* DoubleList_h */
