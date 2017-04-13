//
//  BinarySearchTree.h
//  MegaProject
//
//  Created by Tucker, Jonah on 4/13/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h


template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert > current->getNodeData())
            {
                current = current->getRightChild();
            }
            else //Remove cerr after verfication of understanding
            {
                cerr << "Item exists alread - Exitiing" << endl;
                delete insertMe;
                return
            }
        }
        
        if (previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRoot(previous);
    }
}


#endif /* BinarySearchTree_h */
