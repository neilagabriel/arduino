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

void led_on(struct LED l)
{
    digitalWrite(l.anode  , HIGH);
    digitalWrite(l.cathode, LOW);
}

void led_on_multiple(struct LED leds[], int num_leds)
{
    struct LED l;
    for (int i = 0; i < num_leds; i++)
    {
        l = leds[i];
        led_on(l);
        delayMicroseconds(100);
        led_off(l);
    }
}

void led_off(struct LED l)
{
    digitalWrite(l.anode  , LOW);
    digitalWrite(l.cathode, HIGH);
}

