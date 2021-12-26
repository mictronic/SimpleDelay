
#ifndef _SIMPLEDELAYS_H
#define _SIMPLEDELAYS_H

#include "Arduino.h"

class simpleDelay
{
    bool isElapsedFlag=false;
    bool Enabled=true;
    signed long  millisOffset=0; //sync with different machine time

    unsigned long  Miliseconds=0;
    unsigned long  Period=0;    

    public :

    unsigned long offsetedMillis();
    simpleDelay();
    void sync( unsigned long t ); //sync with different machine time
    bool isElapsed();
    void Set( unsigned long  period );
    void Renew( unsigned long  period );
    signed long Remaining();
    void Enable();
    void Disable();
    bool isEnabled();
        

};

#endif