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

#define ITERATIONS 10
#define INTERVAL   200

struct COORDINATE s1[16];
struct COORDINATE s2[16];
struct COORDINATE s3[16];
struct COORDINATE s4[16];

static void setup_pattern()
{
    for (char x = 0; x < 4; x++)
    {
        for (char z = 0; z < 4; z++)
        {
            char c = (x * 4) + z;

            s1[c].x = x;
            s1[c].y = 0;
            s1[c].z = z;

            s3[c].x = x;
            s3[c].y = 3;
            s3[c].z = z;
        }
    }

    for (char y = 0; y < 4; y++)
    {
        for (char z = 0; z < 4; z++)
        {
            char c = (y * 4) + z;

            s2[c].x = 0;
            s2[c].y = y;
            s2[c].z = z;

            s4[c].x = 3;
            s4[c].y = y;
            s4[c].z = z;
        }
    }
}

static void light(struct COORDINATE c[])
{
    long duration, startTime;
    for (duration = 0, startTime = millis(); 
         duration < INTERVAL; 
         duration = millis() - startTime)
    {
        led_on_multiple2(c, 16);
    }
}

void siren()
{
    setup_pattern();

    for (int i = 0; i < ITERATIONS; i++)
    {
        light(s1);
        light(s2);
        light(s3);
        light(s4);
    }
}

