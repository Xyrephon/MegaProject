//
//  IntNode.cpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/6/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#include "IntNode.hpp"

IntNode :: IntNode()
{
    this->nodeData = -999;
    this->nodePointer = nullptr;
}

IntNode :: IntNode(int data)
{
    this->nodeData = data;
    this->nodePointer = nullptr;
}

IntNode :: IntNode(int nodeData, IntNode * next)
{
    this ->nodeData = nodeData;
    this->nodePointer = next;
}

int IntNode :: getNodeData()
{
    return nodeData;
}

IntNode * IntNode :: getNodePointer()
{
    return nodePointer;
}

void IntNode :: setNodeData(int nodeData)
{
    this->nodeData = nodeData;
}

void IntNode :: setNextPointerIntNode; * next()
{
    this->nodePointer = next;
}
