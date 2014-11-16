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

void spiral()
{
    static int coords[8][3] =
    {
        {0, 0, 1},
        {0, 0, 2},
        {1, 0, 3},
        {2, 0, 3},
        {3, 0, 2},
        {3, 0, 1},
        {2, 0, 0},
        {1, 0, 0},
    };

    for (int j = 0; j < 10; j++)
    {
        struct LED leds[3];
        for (int y = 0; y <=3; y++)
        {
            for (int c1 = 0; c1 < 8; c1++)
            {
                int c2 = (c1 + 7) % 8;
                int c3 = (c1 + 6) % 8;

                leds[0] = get_led(coords[c1][0], y, coords[c1][2]);
                leds[1] = get_led(coords[c2][0], y, coords[c2][2]);
                leds[2] = get_led(coords[c3][0], y, coords[c3][2]);

                for (int i = 0; i < 25; i++)
                    led_on_multiple(leds, 3);
            }
        }
        for (signed int y = 2; y >= 1; y--)
        {
            for (int c = 0; c < 8; c++)
            {
                struct LED led1 = get_led(coords[c][0], y, coords[c][2]);
                led_on(led1);
                delay(50);
                led_off(led1);
            }
        }
    }
}

