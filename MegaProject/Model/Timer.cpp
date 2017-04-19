//
//  Timer.cpp
//  SecondProject
//
//  Created by Tucker, Jonah on 1/31/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#include "Timer.hpp"
#include <iostream>

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer :: startTimer()
{
    executionTime = clock();
}

void Timer :: stopTimer()
{
    executionTime = clock() - executionTime;
}

void Timer :: resetTimer()
{
    executionTime = 0;
}

void Timer :: displayTimerInformation()
{
    cout << "The execution time is: " << executionTime << endl;
    cout << "In human time it is " << double (executionTime)/CLOCKS_PER_SEC << " seconds" << endl;
}

long Timer :: getExecutionTimeInMicroseconds()
{
    
    return executionTime;
}


