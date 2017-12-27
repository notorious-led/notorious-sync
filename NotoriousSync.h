#ifndef NOTORIOUS_SYNC_H
#define NOTORIOUS_SYNC_H


#include "Arduino.h"

class NotoriousSync {
    public:
        NotoriousSync();
        unsigned long ping();
        void setRtt(double rtt);
        double getRtt();

        unsigned long scheduleState(unsigned long delayFromNow, int state);
        int getState();
        void reset();

        double rttFromController;
    private:
        int currentState;
        int desiredState;
        unsigned long desiredStateTime;
};


#endif
