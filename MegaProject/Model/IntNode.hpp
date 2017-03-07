//
//  IntNode.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/6/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nodePointer;
public:
    //Constructors
    IntNode();
    IntNode(int value);
    /*
    Creates an IntNode with a specified value and reference to the next node.
     */
    IntNode(int value, IntNode * nextNode);
    
    //Methods
    int getNodeData();
    IntNode * getNodePointer();
    void setNodeData(int value);
    void setNextPointer (IntNode * next);
    
    
};

#endif /* IntNode_hpp */
