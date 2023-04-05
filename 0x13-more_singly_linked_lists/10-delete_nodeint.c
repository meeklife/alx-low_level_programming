#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given position
 * @head: pointer to the pointer to the first node
 * @index: index of the node to delete (starting from 0)
 *
 * Return: 1 if success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *previous;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    if (index == 0)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
        return (1);
    }

    previous = *head;
    current = (*head)->next;

    for (i = 1; i < index && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return (-1);

    previous->next = current->next;
    free(current);
    return (1);
}

