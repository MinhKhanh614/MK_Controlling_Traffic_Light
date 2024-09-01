#include "kxnTaskLED.h"

#define GREEN 8000
#define YELLOW 2000
#define RED GREEN + YELLOW

kxnTaskLED LED_Green;
kxnTaskLED LED_Red;
kxnTaskLED LED_Yellow;

unsigned long currentMillis = 0, lastMillis = 0, interval = 1000;
long value1, value2, value3;

void setup()
{
    LED_Red.setup(8);
    LED_Green.setup(9);
    LED_Yellow.setup(10);
}

void loop()
{
    LED_Red.write(RED);
    khanhDelay(RED);
    LED_Green.write(GREEN);
    khanhDelay(GREEN);
    LED_Yellow.write(YELLOW);
    khanhDelay(YELLOW);
}

void khanhDelay(unsigned long Time)
{
    static uint8_t callTimes = 0;
    while (millis() <= millis() + Time)
    {
        kxnTaskManager.run(millis());
        currentMillis = millis();
        if (currentMillis - lastMillis >= interval)
        {
            lastMillis = millis();
            Time -= 1000;
            if (Time < 0)
            {
                Time = 0;
            }
        }
    }
    callTimes++;
}