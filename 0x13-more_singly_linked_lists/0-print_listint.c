#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
#include <string.h>
/**
 * print_listint - Prints all the elements of a list.
 * @h: Pointer to the struct.
 * Return: The number.
 */

size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL) {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return count;
}
