#include <stdlib.h>
#include "lists.h"

/**
 * *get_nodeint_at_index - Returns ntn node of a list.
 *
 * @head: Pointer to first node.
 * @index: count of node in the list.
 *
 * Return: The address of node.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    listint_t *current = head;
    unsigned int i = 0;

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    if (i != index || current == NULL)
        return NULL;

    return current;
}

