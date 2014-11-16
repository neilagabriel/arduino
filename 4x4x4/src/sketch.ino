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

void setup()
{
    initialize_cube();
}

void loop()
{
    char i, x, y, z;
    int d;
    led l;

    for (z = 0; z <= 3; z++)
    {
        for (y = 0; y <= 3; y++)
        {
            for (x = 0; x <= 3; x++)
            {
                l = cube[x][y][z];
                led_on(l);
                delay(50);
                led_off(l);
            }
        }
    }

    for (x = 0; x <= 3; x++)
    {
        for (y = 0; y <= 3; y++)
        {
            for (z = 3; z >= 0; z--)
            {
                l = cube[x][y][z];
                led_on(l);
                delay(50);
                led_off(l);
            }
        }
    }

    for (i = 0; i < 64 * 5; i++)
    {
        x = rand() % 4;
        y = rand() % 4;
        z = rand() % 4;

        d = 300;

        l = cube[x][y][z];
        led_on(l);
        delay(d);
        led_off(l);
    }

    for (i = 0; i < 64 * 2; i++)
    {
        x = rand() % 4;
        y = rand() % 4;

        for (z = 3; z >= 0; z--)
        {
            l = cube[x][y][z];
            led_on(l);
            delay(50);
            led_off(l);
        }
    }
}

