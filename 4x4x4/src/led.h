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

#ifndef _LED_H_
#define _LED_H_

struct COORDINATE
{
    char x;
    char y;
    char z;
};

struct LED
{
    char anode;
    char cathode;
};

void led_on(struct LED l);
void led_on_multiple(struct LED leds[], int num_leds);
void led_off(struct LED l);

void coordinate_on(struct COORDINATE coord);
void coordinate_on_multiple(struct COORDINATE coords[], int num_coords);
void coordinate_on_multiple_time(struct COORDINATE coords[], int num_coords, unsigned int time);
void coordinate_off(struct COORDINATE c);

#endif // _LED_H_

