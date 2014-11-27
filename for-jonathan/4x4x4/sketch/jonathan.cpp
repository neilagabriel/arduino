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

void jonathan()
{
    struct COORDINATE J[] =
    {
        {0, 0, 0},
        {1, 0, 0},
        {1, 0, 1},
        {1, 0, 2},
        {1, 0, 3},
        {0, 0, 3},
        {2, 0, 3},
    };

    struct COORDINATE O[] =
    {
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 1},
        {3, 0, 2},
        {2, 0, 3},
        {1, 0, 3},
        {0, 0, 1},
        {0, 0, 2},
    };

    for (int y = 0; y <= 3; y++)
    {
        for (int c = 0; c <= 6; c++)
        {   
            J[c].y = y;
        }        
        coordinate_on_multiple_time(J, 7, 500);
    }

    for (int y = 0; y <= 3; y++)
    {
        for (int c = 0; c <= 7; c++)
        {   
            O[c].y = y;
        }        
        coordinate_on_multiple_time(O, 8, 500);
    }


}

