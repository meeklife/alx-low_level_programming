#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a list.
 * @head: Pointer that points to the struct.
 * @n: Integer in the struct.
 *
 * Return: the adress of the new element.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *newNode = malloc(sizeof(listint_t));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->n = n;
    newNode->next = *head;
    *head = newNode;

    return newNode;
}

