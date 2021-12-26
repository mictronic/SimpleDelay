# SimpleDelay
Non blocking simple delay based on millis() built in arduino .
Library has rollover error free.
Instances at start are default enabled, could be disabled using ```Disable()```.
If instance is disabled, ```isEnabled()``` return false every time until user enabling it manually.

# State check
   - bool isEnabled()
   - bool isElapsed()
   - signed long Remaining()

# Set delay

    - void Set(unsigned long  period)
    - void Renew(unsigned long  period)
    - void Enable()
    - void Disable()

# Time synchronization
    This function is useful for synchronization multiples instances with other time than millis().

    void sync( unsigned long t )

## Installation

### Using PlatformIO

# or using GIT Url (the latest development version)
lib_deps = https://github.com/mictronic/SimpleDelay

## Examples

### Led toggle
```cpp
simpleDelay ledToggle;
#define LED 13

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    if (ledToggle.isElapsed()) {

        if (digitalRead(LED))
            digitalWrite(LED, LOW);
        else
            digitalWrite(LED, HIGH);

        ledToggle.Set(1000); // LED toggles every 1000ms
    }
}
```

### Maintain led at high until switch is pressed
```cpp
simpleDelay ledTimeout;
#define LED 13
#define BUTTON 12

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    if (ledToggle.isElapsed())
        digitalWrite(LED, LOW);

    if (digitalRead(BUTTON) == 0)
        ledToggle.Renew(1000), digitalWrite(LED, HIGH); // renew led timeout
}
```

