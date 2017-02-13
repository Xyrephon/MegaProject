//
//  Node.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/13/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type> * nodePointer;
public:
    //Constructors
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    //Methods
    Type getNodeData();
    Node<Type> * getNodePointer();
    void setNodeData(Type data);
    void setNoderPointer(Node<Type * nextPointer);
};
#endif /* Node_hpp */
