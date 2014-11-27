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

struct COORD_2D
{
    char x;
    char y;
};

#if 0
static struct COORDINATE coord_map[10][13] =
{
//                 x
//  y              0           1           2           3           4           5           6           7           8           9
/*  0 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {0, 3, 0}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  0
/*  1 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  1
/*  2 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  2
/*  3 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  3 
/*  4 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  4 
/*  5 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  5
/*  6 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {3,3,3}},    //  6
/*  7 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  7
/*  8 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  8
/*  9 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, //  9
/* 10 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, // 10
/* 11 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, // 11
/* 12 */ {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}}, // 12
};
#endif

#define nm {-1,-1,-1}
static struct COORDINATE coord_map[][12] =
{
//              y
//  x           0        1        2        3        4        5        6        7        8        9       10        11
/*  0 */ {     nm,      nm,      nm, {0,3,0}, {0,3,1}, {0,3,2}, {0,3,3},      nm,      nm,      nm,      nm,      nm},
/*  1 */ {     nm,      nm,      nm, {0,2,0}, {0,2,1}, {0,2,2}, {0,2,3},      nm,      nm,      nm,      nm,      nm},
/*  2 */ {     nm,      nm,      nm, {0,1,0}, {0,1,1}, {0,1,2}, {0,1,3},      nm,      nm,      nm,      nm,      nm},
/*  3 */ {{0,3,0}, {0,2,0}, {0,1,0}, {0,0,0}, {0,0,1}, {0,0,2}, {0,0,3}, {0,1,3}, {0,2,3}, {0,3,3}, {0,3,2}, {0,3,1}},
/*  4 */ {{1,3,0}, {1,2,0}, {1,1,0}, {1,0,0}, {1,0,1}, {1,0,2}, {1,0,3}, {1,1,3}, {1,2,3}, {1,3,3}, {1,3,2}, {1,3,1}},
/*  5 */ {{2,3,0}, {2,2,0}, {2,1,0}, {2,0,0}, {2,0,1}, {2,0,2}, {2,0,3}, {2,1,3}, {2,2,3}, {2,3,3}, {2,3,2}, {2,3,1}},
/*  6 */ {{3,3,0}, {3,2,0}, {3,1,0}, {3,0,0}, {3,0,1}, {3,0,2}, {3,0,3}, {3,1,3}, {3,2,3}, {3,3,3}, {3,3,2}, {3,3,1}},
/*  7 */ {     nm,      nm,      nm, {3,1,0}, {3,1,1}, {3,1,2}, {3,1,3},      nm,      nm,      nm,      nm,      nm},
/*  8 */ {     nm,      nm,      nm, {3,2,0}, {3,2,1}, {3,2,2}, {3,2,3},      nm,      nm,      nm,      nm,      nm},
/*  9 */ {     nm,      nm,      nm, {3,3,0}, {3,3,1}, {3,3,2}, {3,3,3},      nm,      nm,      nm,      nm,      nm},

/* 10 */ {     nm,      nm,      nm, {2,3,0}, {2,3,1}, {2,3,2}, {2,3,3},      nm,      nm,      nm,      nm,      nm},
/* 11 */ {     nm,      nm,      nm, {1,3,0}, {1,3,1}, {1,3,2}, {1,3,3},      nm,      nm,      nm,      nm,      nm},
/* 12 */ {     nm,      nm,      nm, {0,3,0}, {0,3,1}, {0,3,2}, {0,3,3},      nm,      nm,      nm,      nm,      nm},
};

static int x_offset = 0;
static int y_offset = 0;

void test_pattern()
{
    struct COORD_2D   coord_2d = {7, 5};
    struct COORDINATE led;

    char x =  coord_2d.x;
    char y = (coord_2d.y + y_offset) % 11;
    led = coord_map[x][y];

    if (led.x != -1)
    {
        coordinate_on(led);
        delay(500);
        coordinate_off(led);

        y_offset++;
    }
    else
    {
        y_offset--;
        delay(500);
    }

#if 0
    struct COORDINATE leds[3];
    struct COORD_2D   coords_2d[] =
    {
        {3, 4},
        {4, 6},
        {5, 4}, 
    };

    for (int c = 0; c < 4; c++)
    {
        char x = (coords_2d[c].x + x_offset) % 12;
        char y = (coords_2d[c].y + y_offset) % 11;
        leds[c] = coord_map[x][y];
    }

    long startTime, duration;
    for (duration = 0, startTime = millis(); 
         duration < 400; 
         duration = millis() - startTime)
    {
        led_on_multiple2(leds, 3);
    }

    x_offset++;
    //y_offset++;
#endif
}