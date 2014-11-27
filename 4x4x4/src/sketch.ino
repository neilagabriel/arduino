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

#include "cube.h"

//extern void scan_rows();
//extern void scan_cols();
//extern void random_pattern();
//extern void rain();
//extern void biglittle_box();
//extern void fireworks();
//extern void trapped_box();
//extern void spiral();
//extern void elevator();
//extern void siren();
//extern void spider();
//extern void test_pattern();
extern void jonathan();

void setup()
{
    Serial.begin(9600);
    initialize_cube();
}

void loop()
{
    //scan_rows();
    //scan_cols();
    //random_pattern();
    //rain();
    //biglittle_box();
    //trapped_box();
    //spiral();
    //elevator();
    //siren();
    //spider();
    //fireworks();
    jonathan();
}

