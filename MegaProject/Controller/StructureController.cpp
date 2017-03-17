//
//  StructureController.cpp
//  MegaProject
//
//  Created by Tucker, Jonah on 2/8/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//
#include "IntNodeArray.hpp"
#include "StructureController.hpp"
#include "../Model/Timer.hpp"
#include "../Model/List.h"
#include <iostream>

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
    numberArray = Array<int>(1);
    numbers = List<int>();
    numberStack = Stack<int>();
    numberQueue = Queue<int>();
    numberDoubleList = DoubleList<int>();
    
}


void StructureController :: start()
{
    testLists();
    testStacks();
    
}

void StructureController :: testLists()
{
    numbers.addFront(3);
    numbers.addEnd(8);
    cout << "End should be 8 and is: " << numbers.getEnd()->getNodeData() << endl;
    cout << "Head should be 3 and is: " << numbers.getFront()->getNodeData() << endl;
}

void StructureController :: testStacks()
{
    cout << "Creating a stack..." << endl;
    numberStack.add(10);
    numberStack.push(12);
    cout << "The size should be 2 and is: " << numberStack.getSize() << endl;
    numberStack.pop();
    cout << "The size should be 1 and is: " << numberStack.getSize() << endl;
    numberStack.push(5);
    numberStack.push(2);
    cout << "Peek should be 2 and is: " << numberStack.peek() << endl;
    numberStack.remove(2);
    cout << "Peek should be 5 and is: " << numberStack.peek() << endl;
    cout << "The size is: " << numberStack.getSize() << endl;
    
}

void StructureController :: testArrayTemplate()
{
    cout << "Array Template" << endl;
    Timer arrayTimer;
    arrayTimer.startTimer();
    int test [9];
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    arrayTimer.resetTimer();
    arrayTimer.startTimer();
    numberArray = Array<int>(9);
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    
}
void StructureController :: testNodeTypes()
{
    cout << "Here is a string node" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is an unintialized int node" << endl;
    cout << numberNode.getNodeData() << endl;
}

void StructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
    
    sample.remove(1);
    cout << "This should go 1, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    sample.addAtIndex(1, 7);
    cout << "This should go 1, 7, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
}

void StructureController :: testIntArray()
{
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(3);
    for(int spot = 0; spot < 3; spot ++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
    
    for(int spot = 0; spot < 3; spot++)
    {
        temp.setAtIndex(spot, spot);
    }
    
    for(int spot = 0; spot < temp.getSize(); spot ++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
}


void StructureController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match: " << endl;
    cout << words.getFromIndex(0) << " should be the same as " << copiedWords.getFromIndex(0) << endl;
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    
}

void StructureController :: testListTiming()
{
    DoubleList<int> timingList;
    for(int index = 0; index < 10000; index ++)
    {
        timingList.add(rand());
    }
    
    long slowTime[1000];
    long fastTime[1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds" << endl;
    
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds" << endl;
    
    cout << "A time savings?? of: " << averageSlow - averageFast << " microseconds";
}
