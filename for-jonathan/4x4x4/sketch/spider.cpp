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

#define REFRESH_INTERVAL 400
#define ITERATIONS       10

static char y_series[] = {0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1};
static char z_series[] = {0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0};

static long refresh_interval;

struct POINT
{
    char x;
    char offset;
};

#if 0
static struct POINT pattern[] =
{
    {0, 0},
    {3, 0},
    {0, 3},
    {3, 3},
};
#define NUM_LEDS 4
#endif

#if 1
static struct POINT pattern[] =
{
    {0, 0},
    {3, 0},
    {0, 3},
    {3, 3},
    {1, 1},
    {1, 2},
    {2, 1},
    {2, 2},
};
#define NUM_LEDS 8
#endif

// box
#if 0
static struct POINT pattern[] =
{
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 0},
    {2, 0},
    {3, 0},
    {3, 1},
    {3, 2},
    {3, 3},
    {1, 3},
    {2, 3},
};
#define NUM_LEDS 13
#endif

#if 0
static struct POINT pattern[] =
{
    {1, 3},
    {1, 2},
    {1, 1},
    {0, 2},
    {0, 1},
    {2, 2},
    {2, 1},
    {2, 0},
    {3, 2},
    {3, 1},
};
#define NUM_LEDS 10
#endif

static char index = 0;

static void update()
{
    struct LED leds[NUM_LEDS];

    for (int c = 0; c < NUM_LEDS; c++)
    {
        char y_offset = (index + pattern[c].offset) % 12;
        char z_offset = (index + pattern[c].offset) % 12;

        char x = pattern[c].x;
        char y = y_series[y_offset];
        char z = z_series[z_offset];

        leds[c] = get_led(x, y, z);
    }

    long startTime, duration;
    for (duration = 0, startTime = millis(); 
         duration < refresh_interval; 
         duration = millis() - startTime)
    {
        led_on_multiple(leds, NUM_LEDS);
    }
}

void spider()
{
    int num_updates = (ITERATIONS * 12) + 1;

    refresh_interval = REFRESH_INTERVAL;
    index = 0;

    for (int i = 0; i < num_updates; i++) 
    {
        update();
        index = (index + 1) % 12;

        if (i % 12 == 0)
        {
            refresh_interval -= 50;
        }
    }
}

