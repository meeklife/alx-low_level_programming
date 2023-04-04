#include <stdlib.h>
#include <stddef.h>
#include "lists.h"
/**
 * istint_len - Returns the number of a element in a linked list.
 * @h: Pointer to the struct.
 * Return: the number of elements.
 */

size_t listint_len(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL) {
        count++;
        h = h->next;
    }

    return count;
}

