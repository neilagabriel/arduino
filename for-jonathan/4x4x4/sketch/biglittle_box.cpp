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

#include "led.h"
#include "cube.h"

#define ITERATIONS 8
#define INTERVAL   250

void biglittle_box()
{
    struct LED big[8];
    struct LED little[8];

    big[0] = get_led(0, 0, 0);
    big[1] = get_led(0, 0, 3);
    big[2] = get_led(3, 0, 0);
    big[3] = get_led(3, 0, 3);
    big[4] = get_led(0, 3, 0);
    big[5] = get_led(0, 3, 3);
    big[6] = get_led(3, 3, 0);
    big[7] = get_led(3, 3, 3);

    little[0] = get_led(1, 1, 1);
    little[1] = get_led(1, 1, 2);
    little[2] = get_led(2, 1, 1);
    little[3] = get_led(2, 1, 2);
    little[4] = get_led(1, 2, 1);
    little[5] = get_led(1, 2, 2);
    little[6] = get_led(2, 2, 1);
    little[7] = get_led(2, 2, 2);

    for (int i = 0; i < ITERATIONS; i++)
    {
        long startTime, duration;

        for (duration = 0, startTime = millis(); 
             duration < INTERVAL; 
             duration = millis() - startTime)
        {
            led_on_multiple(big, 8);
        }

        for (duration = 0, startTime = millis(); 
             duration < INTERVAL; 
             duration = millis() - startTime)
        {
            led_on_multiple(little, 8);
        }
    }
}

