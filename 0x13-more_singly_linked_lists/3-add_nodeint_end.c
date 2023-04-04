#include <stdlib.h>
#include <stddef.h>
#include "lists.h"
/**
 * add_nodeint_end - Adds a new node at the end of a list.
 * @head: pointer to first node.
 * @n: Int to be added.
 * Return: The address of the new element.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *newNode = malloc(sizeof(listint_t));
    listint_t *lastNode = *head;

    if (newNode == NULL) {
        return NULL;
    }

    newNode->n = n;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return newNode;
    }

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    return newNode;
}

