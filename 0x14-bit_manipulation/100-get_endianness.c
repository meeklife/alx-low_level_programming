#include "main.h"
/**
 * get_endianness - Cecks the endianness.
 * Return: 0
 */

int get_endianness(void)
{
    unsigned int x = 0x12345678;
    char *c = (char*) &x;

    // If the first byte of x is the least significant byte, then we are on a
    // little-endian machine; otherwise, we are on a big-endian machine.
    if (*c == 0x78)
        return 1; // little endian
    else
        return 0; // big endian
}

