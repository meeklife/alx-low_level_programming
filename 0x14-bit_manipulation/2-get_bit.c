#include "main.h"
/**
 *  get_bit - Returns the value of a bit at a given index.
 * @n: numbert to find a index bit.
 * @index: the bit to return.
 * Return: the value of the bit index or -1 if an error occured.
 */

int get_bit(unsigned long int n, unsigned int index) {
    if (index >= (sizeof(unsigned long int) * 8)) {
        return -1;  // index out of bounds
    }
    unsigned long int mask = 1;
    mask <<= index;
    return (n & mask) ? 1 : 0;
}

