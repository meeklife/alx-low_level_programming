#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a list.
 * @head: Pointer to first node.
 * Return: n or 0.
 */

int pop_listint(listint_t **head)
{
    listint_t *current;
    int n;

    if (head == NULL || *head == NULL)
        return 0;

    current = *head;
    *head = current->next;
    n = current->n;
    free(current);

    return n;
}

