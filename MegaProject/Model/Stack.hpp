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
 Empty since the base class constructor is fabu
*/
template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}

/*
 No Need to change this from Queue - so it was copied
*/
template <class Type>
Stack<Type> :: ~Stack()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

/*
 The add method only adds to the end on a stack. Never at an index
 */

template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}

/*
 1. Creates a new node
 2. If the stack is empty sets front to the new node
 3. Else sets the end's next to point to the new node and the new node's previous to end
 4. Move end to the new node.
 5. Increases the size by 1.
*/
template <class Type>
void Stack<Type> :: push(Type addThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
 
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(addToStack);
    }
    else
    {
        this->getEnd->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addToStack);
    this->size++;
}

/*
 Use to avoid abstract status
 Asserts that the size is correct and calls the pop method.
*/
template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
}

template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->getSize() > 0);
    return this->end->getNodeData();
}

/*
 1. Assert size > 0;
 2. Get data from end node.
 3. Move end to end's previous
 4. Delete old end node.
 5. Decrease size.
 6. Return data from old end.
*/
template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    
    delete this->getEnd();
    
    this->setEnd(update);
    
    this->setSize(this->getSize() - 1);
    
    return removed;
}


#endif /* Stack_h */
