//
//  StructureController.hpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/8/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "../Model/Node.hpp"
#include "../Model/Array.hpp"
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.h"
#include "../Model/DoubleList.hpp"
#include "../Model/Stack.hpp"
#include "../Model/Queue.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/Graph.hpp"
#include "../Model/HashNode.hpp"
#include "../Model/HashTable.hpp"
#include <string>

using namespace std;

class StructureController
{
private:
    Node<int> numberNode;
    Node<string> wordNode;
    Array<int> numberArray;
    List<int> numbers;
    Stack<int> numberStack;
    Queue<int> numberQueue;
    DoubleList<int> numberDoubleList;
    Graph<string> stringGraph;
    HashTable<int> intHash;
    
    void testBinarySearchTreeOperations();
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();
    void testListIntro();
    void testListTiming();
    void testLists();
    void testStacks();
    void testQueues();
    void testDoubleList();
    void testGraph();
    void testHashTable();
public:
    StructureController();
    void start();
};

#endif /* StructureController_hpp */
