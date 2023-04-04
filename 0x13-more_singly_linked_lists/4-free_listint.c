#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */

void free_listint(listint_t *head)
{
    listint_t *nextNode;

    while (head != NULL) {
        nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

