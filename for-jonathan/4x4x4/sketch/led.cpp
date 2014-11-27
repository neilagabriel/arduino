/*
 * This file is part of 4x4x4.
 *
 * 4x4x4 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * 4x4x4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 4x4x4.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Arduino.h"
#include "cube.h"
#include "led.h"

void led_on(struct LED l)
{
    digitalWrite(l.anode  , HIGH);
    digitalWrite(l.cathode, LOW);
}

void led_on_multiple(struct LED leds[], int num_leds)
{
    struct LED l;
    for (int i = 0; i < num_leds; i++)
    {
        l = leds[i];
        led_on(l);
        delayMicroseconds(100);
        led_off(l);
    }
}

void led_off(struct LED l)
{
    digitalWrite(l.anode  , LOW);
    digitalWrite(l.cathode, HIGH);
}

void coordinate_on(struct COORDINATE c)
{
    struct LED l = get_led(c.x, c.y, c.z);
    led_on(l);
}

void coordinate_on_multiple(struct COORDINATE coords[], int num_coords)
{
    struct COORDINATE c;
    struct LED l;

    for (int i = 0; i < num_coords; i++)
    {
        c = coords[i];
        l = get_led(c.x, c.y, c.z);

        led_on(l);
        delayMicroseconds(100);
        led_off(l);
    }
}

void coordinate_on_multiple_time(struct COORDINATE coords[], int num_coords, unsigned int time)
{
    long startTime, duration;
    for (duration = 0, startTime = millis(); 
         duration < time; 
         duration = millis() - startTime)
    {
        coordinate_on_multiple(coords, num_coords);
    }
}

void coordinate_off(struct COORDINATE c)
{
    struct LED l = get_led(c.x, c.y, c.z);
    led_off(l);
}

