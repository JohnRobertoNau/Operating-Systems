#include <stdio.h>
#include <unistd.h>

int puts(const char *str)
{
    const char *copy = str;
    int len = 0;
    while (*copy) {
        len++;
        copy++;
    }

    int byte = write(1, str, len);
    if (byte < 0) {
        return -1;
    }

    byte = write(1, "\n", 1);
    if (byte < 0) {
        return -1;
    }
    return 0;
}
