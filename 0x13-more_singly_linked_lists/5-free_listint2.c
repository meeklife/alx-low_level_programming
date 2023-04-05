#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a list.
 * @head: Address of the first node of a list.
 **/

void free_listint2(listint_t **head)
{
    listint_t *current;

    if (head == NULL)
        return;

    while (*head != NULL) {
        current = *head;
        *head = current->next;
        free(current);
    }

    *head = NULL;
}

