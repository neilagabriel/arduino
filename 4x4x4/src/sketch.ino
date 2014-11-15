#define L103 {2,10}
#define L102 {2,11}
#define L101 {2,12}
#define L100 {2,13}
#define L303 {2,14}
#define L302 {2,15}
#define L301 {2,16}
#define L300 {2,17}
#define L113 {3,10}
#define L112 {3,11}
#define L111 {3,12}
#define L110 {3,13}
#define L313 {3,14}
#define L312 {3,15}
#define L311 {3,16}
#define L310 {3,17}
#define L123 {4,10}
#define L122 {4,11}
#define L121 {4,12}
#define L120 {4,13}
#define L323 {4,14}
#define L322 {4,15}
#define L321 {4,16}
#define L320 {4,17}
#define L133 {5,10}
#define L132 {5,11}
#define L131 {5,12}
#define L130 {5,13}
#define L333 {5,14}
#define L332 {5,15}
#define L331 {5,16}
#define L330 {5,17}
#define L003 {6,10}
#define L002 {6,11}
#define L001 {6,12}
#define L000 {6,13}
#define L203 {6,14}
#define L202 {6,15}
#define L201 {6,16}
#define L200 {6,17}
#define L013 {7,10}
#define L012 {7,11}
#define L011 {7,12}
#define L010 {7,13}
#define L213 {7,14}
#define L212 {7,15}
#define L211 {7,16}
#define L210 {7,17}
#define L023 {8,10}
#define L022 {8,11}
#define L021 {8,12}
#define L020 {8,13}
#define L223 {8,14}
#define L222 {8,15}
#define L221 {8,16}
#define L220 {8,17}
#define L033 {9,10}
#define L032 {9,11}
#define L031 {9,12}
#define L030 {9,13}
#define L233 {9,14}
#define L232 {9,15}
#define L231 {9,16}
#define L230 {9,17}


struct led
{
    char anode;
    char cathode;
};

struct led cube[4][4][4] =
{
    // x=0
    {
        //z=0   z=1   z=2   z=3 
        {L000, L001, L002, L003}, // y=0
        {L010, L011, L012, L013}, // y=1
        {L020, L021, L022, L023}, // y=2
        {L030, L031, L032, L033}, // y=3
    },
    // x=1
    {
        //z=0   z=1   z=2   z=3
        {L100, L101, L102, L103}, // y=0
        {L110, L111, L112, L113}, // y=1
        {L120, L121, L122, L123}, // y=2
        {L130, L131, L132, L133}, // y=3
    },
    // x=2
    {   //z=0   z=1   z=2   z=3
        {L200, L201, L202, L203}, // y=0
        {L210, L211, L212, L213}, // y=1
        {L220, L221, L222, L223}, // y=2
        {L230, L231, L232, L233}, // y=3
    },
    // x=3
    {   //z=0   z=1   z=2   z=3
        {L300, L301, L302, L303}, // y=0
        {L310, L311, L312, L313}, // y=1
        {L320, L321, L322, L323}, // y=2
        {L330, L331, L332, L333}, // y=3
    },
};


void led_on(struct led l)
{
    digitalWrite(l.anode  , HIGH);
    digitalWrite(l.cathode, LOW);
}

void led_off(struct led l)
{
    digitalWrite(l.anode  , LOW);
    digitalWrite(l.cathode, HIGH);
}

// Anodes   02-09
// Cathodes 10-17

void setup()
{
    int pin;

    // 2-17 are output pins
    for (pin = 2; pin <= 17; pin++)
        pinMode(pin, OUTPUT);

    // Initialize anodes
    for (pin = 2; pin <= 9; pin++)
        digitalWrite(pin, LOW);

    // Initialize cathodes
    for (pin = 10; pin <= 17; pin++)
        digitalWrite(pin, HIGH);
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

        d = 2; 

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

// x, y, z | a,  c
// --------+-------
// 1, 0, 3 | 2, 10
// 1, 0, 2 | 2, 11
// 1, 0, 1 | 2, 12
// 1, 0, 0 | 2, 13
// 3, 0, 3 | 2, 14
// 3, 0, 2 | 2, 15
// 3, 0, 1 | 2, 16
// 3, 0, 0 | 2, 17
// --------+-------
// 1, 1, 3 | 3, 10
// 1, 1, 2 | 3, 11
// 1, 1, 1 | 3, 12
// 1, 1, 0 | 3, 13
// 3, 1, 3 | 3, 14
// 3, 1, 2 | 3, 15
// 3, 1, 1 | 3, 16
// 3, 1, 0 | 3, 17
// --------+-------
// 1, 2, 3 | 4, 10
// 1, 2, 2 | 4, 11
// 1, 2, 1 | 4, 12
// 1, 2, 0 | 4, 13
// 3, 2, 3 | 4, 14
// 3, 2, 2 | 4, 15
// 3, 2, 1 | 4, 16
// 3, 2, 0 | 4, 17
// --------+-------
// 1, 3, 3 | 5, 10
// 1, 3, 2 | 5, 11
// 1, 3, 1 | 5, 12
// 1, 3, 0 | 5, 13
// 3, 3, 3 | 5, 14
// 3, 3, 2 | 5, 15
// 3, 3, 1 | 5, 16
// 3, 3, 0 | 5, 17

// --------+-------
// 0, 0, 3 | 6, 10
// 0, 0, 2 | 6, 11
// 0, 0, 1 | 6, 12
// 0, 0, 0 | 6, 13
// 2, 0, 3 | 6, 14
// 2, 0, 2 | 6, 15
// 2, 0, 1 | 6, 16
// 2, 0, 0 | 6, 17
// --------+-------
// 0, 1, 3 | 7, 10
// 0, 1, 2 | 7, 11
// 0, 1, 1 | 7, 12
// 0, 1, 0 | 7, 13
// 2, 1, 3 | 7, 14
// 2, 1, 2 | 7, 15
// 2, 1, 1 | 7, 16
// 2, 1, 0 | 7, 17
// --------+-------
// 0, 2, 3 | 8, 10
// 0, 2, 2 | 8, 11
// 0, 2, 1 | 8, 12
// 0, 2, 0 | 8, 13
// 2, 2, 3 | 8, 14
// 2, 2, 2 | 8, 15
// 2, 2, 1 | 8, 16
// 2, 2, 0 | 8, 17
// --------+-------
// 0, 3, 3 | 9, 10
// 0, 3, 2 | 9, 11
// 0, 3, 1 | 9, 12
// 0, 3, 0 | 9, 13
// 2, 3, 3 | 9, 14
// 2, 3, 2 | 9, 15
// 2, 3, 1 | 9, 16
// 2, 3, 0 | 9, 17

