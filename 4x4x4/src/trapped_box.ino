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

static char coords[8][3] =
{
    {0, 0, 0},
    {0, 0, 1},
    {1, 0, 0},
    {1, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 1, 0},
    {1, 1, 1},
};

static signed char direction[3] = {1, 1, 1};

static void shift(char dim)
{
    for (char c = 0; c < 8; c++)
        coords[c][dim] += direction[dim];

    if (direction[dim] > 0)
    {
        if (coords[0][dim] == 2)
            direction[dim] = -1;
    }
    else
    {
        if (coords[0][dim] == 0)
            direction[dim] = 1;
    }
}

static void update()
{
    struct LED leds[8];
    for (char c = 0; c < 8; c++)
    {
        leds[c] = get_led(coords[c][0], 
                          coords[c][1], 
                          coords[c][2]);
    }
    for (char i = 0; i < 20; i++)
        led_on_multiple(leds, 8);
}

void trapped_box()
{
    for (int i = 0; i < 25; i++)
    {
        char dim = rand() % 3;
        shift(dim);

        char dim2 = dim;
        while (dim2 == dim)
        {
            dim2 = rand() % 3;
        }
        shift(dim2);

        update();
    }
}

