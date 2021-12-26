#include "simpleDelay.h"

simpleDelay::simpleDelay()
{
    isElapsedFlag=false;
    Miliseconds=0;
    Period=0;
    Enabled=true;
    millisOffset=0;
}

unsigned long simpleDelay::offsetedMillis()
{
    return (unsigned long)millis()-millisOffset;
}

void simpleDelay::sync( unsigned long t ) //sync with different machine time
{
    millisOffset=(signed long)millis()-t;
    Miliseconds=offsetedMillis();
}

signed long simpleDelay::Remaining()
{
    return ((signed long)Miliseconds+Period)-offsetedMillis();
}

bool simpleDelay::isElapsed()
{
    if( ((unsigned long)offsetedMillis() - Miliseconds) > Period ) 
    {
        isElapsedFlag=false;
        return Enabled;
    }
    return false; 
}

void simpleDelay::Enable()
{
    Enabled=true;
}

void simpleDelay::Disable()
{
    Enabled=false;
}

bool simpleDelay::isEnabled()
{
    return Enabled;
}

void simpleDelay::Set(unsigned long  period)
{
    if( !isElapsedFlag ) 
    {
        Miliseconds  = offsetedMillis();
        Period=period;
        isElapsedFlag=true;
    }
    //Serial.printf("Val=%ld\r\n",Miliseconds);
}

void simpleDelay::Renew(unsigned long  period)
{

    Miliseconds = offsetedMillis();
    Period = period;
    isElapsedFlag = true;

}