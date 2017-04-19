//
//  List.h
//  MegaProject
//
//  Created by Tucker, Jonah on 2/21/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include "Node.hpp"

template <class Type>
class List
{
private:
    int size;
    Node<Type>* front;
    Node<Type>* end;
public:
    //Constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
    //Methods
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    void addEnd(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
};

//Implementation

template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}

template <class Type>
List<Type> :: List(const List<Type> & source)
{
    
}

template <class Type>
List<Type> :: ~List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}

template <class Type>
void List<Type> :: addFront(Type value)
{
    if (size == 0)
    {
        Node<Type> * first = new Node<Type>(value);
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNextPointer(front);
        //or
        //Node<Type> * newFirst = new Node<Type>(value, front);
        front = newFirst;
    }
    
    size++;
}


template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if (size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNextPointer(added);
        this->end = added;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
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
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
        
        size++;
    }
}

template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = front->getNodePointer();
    }
    else if(index == size -1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        previous->setNextPointer(nullptr);
        this->end = previous;
        
    }
    else
    {
        
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNodePointer();
        previous->setNextPointer(current);
        
    }
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    
    size--;
    return removed;
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type information;
    
    Node<Type> * current = front;
    for (int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    information = current->getNodeData();
    
    return information;
}

template <class Type>
bool List<Type> :: contains(Type findMe)
{
    bool isInList = false;
    Node<Type> * current = front;
    
    for (int index = 0; index < size; index ++)
    {
        if(current->getNodeData == findMe)
        {
            isInList = true;
            return isInList;
        }
        current = current->getNodePointer();
    }
    
    return isInList;
}

template <class Type>
int List<Type> :: getSize() const
{
    return this->size;
}

template <class Type>
Node<Type> * List<Type> :: getFront() const
{
    return this->front;
}

template <class Type>
Node<Type> * List<Type> :: getEnd() const
{
    return this->end;
}

#endif /* List_h */
