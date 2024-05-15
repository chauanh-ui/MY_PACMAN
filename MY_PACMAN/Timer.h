#pragma once
#include "Common.h"
class Timer {
public:
    Timer();
    void Start();
    void Reset();
    void Restart();
    void Pause();
    void Unpause();
    long GetTicks();
    bool isStarted();
    bool isPaused();
private:
    long StartTicks;	//Ticks since start
    long PausedTicks;   //Ticks since stop
    bool Paused;
    bool Started;
};
