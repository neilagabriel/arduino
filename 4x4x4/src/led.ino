#include "led.h"

void led_on(struct led l)
{
    digitalWrite(l.anode  , HIGH);
    digitalWrite(l.cathode, LOW);
}

void led_off(struct led l)
{
    digitalWrite(l.anode  , LOW);
    digitalWrite(l.cathode, HIGH);
}

