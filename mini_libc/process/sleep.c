#include <stdio.h>
#include <time.h>

unsigned int sleep(unsigned int sec) {
    struct timespec requested, remaining;
    requested.tv_sec = sec;
    requested.tv_nsec = 0;

    if (nanosleep(&requested, &remaining) != 0) {
        return remaining.tv_sec;
    }
    return 0;
}
