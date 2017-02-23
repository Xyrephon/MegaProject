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
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    int getSize() const;
    Node<Type>* getFront() const;
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
List<Type> :: ~List<Type>()
{
    
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    
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
        newFirst->setNodePointer(front);
        //or
        //Node<Type> * newFirst = new Node<Type>(value, front);
        front = newFirst;
    }
    
    size++;
}

#endif /* List_h */
