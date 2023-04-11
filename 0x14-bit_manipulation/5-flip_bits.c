#include "main.h"
/**
 * flip_bits - Function that returns the number of bits.
 * @n: First number.
 * @m: Second number.
 * Return: Number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int diff = n ^ m;
    unsigned int count = 0;
    while (diff)
    {
        count += diff & 1;
        diff >>= 1;
    }
    return count;
}

