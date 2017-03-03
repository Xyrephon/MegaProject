//
//  Stack.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 3/1/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
};

/*
 The add method only adds to the end on a stack. Never at an index
 */

template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}

#endif /* Stack_h */
