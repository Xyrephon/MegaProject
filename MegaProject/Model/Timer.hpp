//
//  Timer.hpp
//  SecondProject
//
//  Created by Tucker, Jonah on 1/31/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>
class Timer
{
private:
    clock_t executionTime;
public:
//    Constructors
    Timer();
//    Methods
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExecutionTimeInMicroseconds();
};

#endif /* Timer_hpp */
