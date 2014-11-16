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

void rain()
{
    char i, x, y, z;

    for (i = 0; i < 16; i++)
    {
        x = rand() % 4;
        y = rand() % 4;

        struct LED l = get_led(x, y, 3);
        led_on(l);
        delay(300);
        led_off(l);

        for (z = 2; z >= 0; z--)
        {
            struct LED l = get_led(x, y, z);

            led_on(l);
            delay(20);
            led_off(l);
        }

        delay(500);
    }
}

