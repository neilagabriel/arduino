#include "led.h"
#include "cube.h"

void setup()
{
    initialize_cube();
}

void loop()
{
    char i, x, y, z;
    int d;
    led l;

    for (z = 0; z <= 3; z++)
    {
        for (y = 0; y <= 3; y++)
        {
            for (x = 0; x <= 3; x++)
            {
                l = cube[x][y][z];
                led_on(l);
                delay(50);
                led_off(l);
            }
        }
    }

    for (x = 0; x <= 3; x++)
    {
        for (y = 0; y <= 3; y++)
        {
            for (z = 3; z >= 0; z--)
            {
                l = cube[x][y][z];
                led_on(l);
                delay(50);
                led_off(l);
            }
        }
    }

    for (i = 0; i < 64 * 5; i++)
    {
        x = rand() % 4;
        y = rand() % 4;
        z = rand() % 4;

        d = 300;

        l = cube[x][y][z];
        led_on(l);
        delay(d);
        led_off(l);
    }

    for (i = 0; i < 64 * 2; i++)
    {
        x = rand() % 4;
        y = rand() % 4;

        for (z = 3; z >= 0; z--)
        {
            l = cube[x][y][z];
            led_on(l);
            delay(50);
            led_off(l);
        }
    }
}

