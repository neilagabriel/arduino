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

#ifndef _CUBE_H_
#define _CUBE_H_

void initialize_cube(void);

extern struct LED cube[4][4][4];
extern struct LED get_led(char x, char y, char z);

#endif // _CUBE_H_
