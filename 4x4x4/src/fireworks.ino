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

#include "led.h"
#include "cube.h"

static struct COORDINATE pattern1[] = 
{
    {0, 0, 0},
    {0, 0, 1},
    {0, 0, 2},
    {1, 1, 3},
    {2, 2, 3},
    {3, 3, 3},
};
static struct COORDINATE pattern2[] = 
{
    {0, 3, 0},
    {0, 3, 1},
    {0, 3, 2},
    {1, 2, 3},
    {2, 1, 3},
    {3, 0, 3},
};
#define NUM_LEDS 5

void fireworks()
{
    long startTime, duration;
    struct LED led;

    for (int c = 0; c <= NUM_LEDS; c++)
    {
        led = get_led(pattern1[c].x, 
                      pattern1[c].y,
                      pattern1[c].z);

        led_on(led);
        delay(250);
        led_off(led);
    }

    for (duration = 0, startTime = millis(); 
         duration < 1500; 
         duration = millis() - startTime)
    {
        char x = 2 + (rand() % 2);
        char y = 2 + (rand() % 2);
        char z = 2 + (rand() % 2);

        led = get_led(x, y, z);
        led_on(led);
        delay(15);
        led_off(led);
    }

    for (int c = 0; c <= NUM_LEDS; c++)
    {
        led = get_led(pattern2[c].x, 
                      pattern2[c].y,
                      pattern2[c].z);

        led_on(led);
        delay(250);
        led_off(led);
    }

    for (duration = 0, startTime = millis(); 
         duration < 1500; 
         duration = millis() - startTime)
    {
        char x = 2 + (rand() % 2);
        char y = rand() % 2;
        char z = 2 + (rand() % 2);

        led = get_led(x, y, z);
        led_on(led);
        delay(15);
        led_off(led);
    }
}
