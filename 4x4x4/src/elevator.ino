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

void elevator()
{
    struct COORDINATE coords[16];
    char z_series[] = 
    {
        0, 
        1, 0, 
        1, 2, 1, 0, 
        1, 2, 3, 2, 1, 0, 
        1, 2, 1, 0,
        1, 0, 
    };

    for (char z = 0; z < sizeof(z_series)/sizeof(char); z++)
    {
        for (char x = 0; x < 4; x++)
        {
            for (char y = 0; y < 4; y++)
            {
                char c = (x * 4) + y;
                coords[c].x = x;
                coords[c].y = y;
                coords[c].z = z_series[z];
            }
        }
        
        long duration, startTime;
        for (duration = 0, startTime = millis(); 
             duration < 400; 
             duration = millis() - startTime)
        {
            coordinate_on_multiple(coords, 16);
        }
    }
}

