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


/*
Adds the supplied object to the stack to the end.
 Set new object to point to end.
 Increases the size by 1.
 Adjusts the end pointer to reflect the new end of the stack.
*/
template <class Type>
void Stack<Type> :: push(Type addThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
 
    if(this->size == 0 || this->front == nullptr || this->end == nullptr)
    {
        this->front = addToStack;
    }
    else
    {
        this->end->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->end);
    }
    this->end = addToStack;
    this->size++;
}

template <class Type>
Type Queue<Type> :: remove (int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

/*
 1. Assert size is valid.
 2. Get data from front node.
 3. If size == 1, set ned to nullptr
 4. Else, move front to front's next
 4a Set front's previous to nullptr
 5. delete old front node
 6. Adjust size down by 1
 7. return old value
*/
template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() > 0);
    
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<Type> * removeMe = this->getFront();
    
    if(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    else
    {
        this->setFront(removeMe->getNextPointer())
    }
    this-setFront()->setPreviousPointer(nullptr);
    
    delete removeMe;
    this->setSize(this->getSize() - 1);
    
    return removedValue;
}

/*
 1. Check that size is greater than 0.
 2. Return the front object's data.
*/
template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->getSize() > 0);
    
    return this->getFront()->getNodeData();
}

#endif /* Stack_h */
