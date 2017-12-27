#include "Arduino.h"
#include "NotoriousSync.h"

#define NOTORIOUS_SYNC_DEBUG

NotoriousSync::NotoriousSync() {
    currentState = -1;
    desiredStateTime = 0;
}

unsigned long NotoriousSync::ping() {
    return millis();
}

void NotoriousSync::setRtt(double rtt) {
    rttFromController = rtt;
}

double NotoriousSync::getRtt() {
    return rttFromController;
}

unsigned long NotoriousSync::scheduleState(unsigned long delayFromNow, int state) {
    desiredState = state;
    desiredStateTime = millis() + delayFromNow - ( rttFromController / 2 );

    #ifdef NOTORIOUS_SYNC_DEBUG
    Serial.print(String("[nsync] It's ") + millis() + " - event scheduled for " + desiredStateTime);
    #endif

    return desiredStateTime;
}

int NotoriousSync::getState() {
    if ( desiredStateTime > 0 && millis() > desiredStateTime ) {
        #ifdef NOTORIOUS_SYNC_DEBUG
        Serial.println("[nsync] It's time. Setting state");
        #endif

        currentState = desiredState;
    }
    return currentState;
}

void NotoriousSync::reset() {
    currentState = -1;
    desiredStateTime = -1;
}

