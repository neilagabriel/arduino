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

static struct COORDINATE J[] =
{
    {3, 0, 3},
    {3, 0, 2},
    {3, 0, 1},
    {3, 0, 0},
    {2, 0, 0},
    {1, 0, 0},
    {1, 0, 1},
};

static struct COORDINATE O[] =
{
    {3, 0, 2},
    {3, 0, 1},
    {3, 0, 0},
    {2, 0, 0},
    {1, 0, 0},
    {1, 0, 1},
    {1, 0, 2},
    {2, 0, 2},
};

static struct COORDINATE N[] =
{
    {1, 0, 2},
    {1, 0, 1},
    {1, 0, 0},
    {2, 0, 1},
    {3, 0, 2},
    {3, 0, 1},
    {3, 0, 0},
};

#define J_SIZE (sizeof(J)/sizeof(struct COORDINATE))
#define O_SIZE (sizeof(O)/sizeof(struct COORDINATE))
#define N_SIZE (sizeof(N)/sizeof(struct COORDINATE))

void jonathan()
{
    coordinate_on_multiple_time(J, J_SIZE, 1000);
    coordinate_on_multiple_time(O, O_SIZE, 1000);
    coordinate_on_multiple_time(N, N_SIZE, 1000);
}
