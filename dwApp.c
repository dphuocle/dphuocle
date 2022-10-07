#include <stdbool.h>
#include <stdlib.h>

#include "digital_wheel.h"

static void run(digital_wheel w, int speed)
{
    bool round;
    while (speed > 0)
    {
        round = digital_wheel_move_to_next_position(w);
        if (!round)
            puts("new round:");
        speed--;    
    }
}
static void display(char *s, int w1)
{
    printf("%s[ %2d ]\n", s, w1);
}

int main(int argc, char **argv)
{

    int max = argc >= 2 ? strtol(argv[1], NULL, 10) : -1;
    int speed = argc >= 3 ? strtol(argv[2], NULL, 10) : -1;

    digital_wheel w1 = digital_wheel_construct(0, max);
    display("Departure with\n", digital_wheel_get_current_position(w1));
    int i = 7;
    puts("Wheeling:");
    while (i-- > 0)
    {
        run(w1, speed);
        display('--',digital_wheel_get_current_position);
    }
}
