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
    Node<Type>* front;
    int size;
public:
    //Constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
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
void List<Type> ::

#endif /* List_h */
