//
//  BiDirectionalNode.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/27/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BIDirectionalNode : public Node<Type>
{
private:
    Type data;
    BiDirectionalNode<Type> * next;
    BiDirectionalNode<Type> * previous;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode <Type> * next);
    
    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDriectionalNode() : Node()
{
    
}


template <class Type>
BiDirectionalNode<Type> :: BiDriectionalNode(Type data) : Node(data)
{
    
}




#endif /* BiDirectionalNode_h */
