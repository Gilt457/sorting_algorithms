#include "sort.h"

void swap_next(listint_t **head, listint_t **end, listint_t **node);
void swap_prev(listint_t **head, listint_t **end, listint_t **node);
void cocktail_sort_list(listint_t **head);

/**
 * swap_next - Swap a node in a listint_t doubly-linked list
 *             of integers with the next node.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @node: A pointer to the current node of the cocktail sort algorithm.
 */
void swap_next(listint_t **head, listint_t **end, listint_t **node)
{
	listint_t *aux = (*node)->next;

	if ((*node)->prev)
		(*node)->prev->next = aux;
	else
		*head = aux;
	aux->prev = (*node)->prev;
	(*node)->next = aux->next;
	if (aux->next)
		aux->next->prev = *node;
	else
		*end = *node;
	(*node)->prev = aux;
	aux->next = *node;
	*node = aux;
}

/**
 * swap_prev - Swap a node in a listint_t doubly-linked list
 *             of integers with the previous node.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @node: A pointer to the current node of the cocktail sort algorithm.
 */
void swap_prev(listint_t **head, listint_t **end, listint_t **node)
{
	listint_t *aux = (*node)->prev;

	if ((*node)->next)
		(*node)->next->prev = aux;
	else
		*end = aux;
	aux->next = (*node)->next;
	(*node)->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = *node;
	else
		*head = *node;
	(*node)->next = aux;
	aux->prev = *node;
	*node = aux;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers
 *                      in ascending order using the cocktail sort algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *end, *node;
	bool sorted = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (end = *head; end->next != NULL;)
		end = end->next;

	while (sorted == false)
	{
		sorted = true;
		for (node = *head; node != end; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swap_next(head, &end, &node);
				print_list((const listint_t *)*head);
				sorted = false;
			}
		}
		for (node = node->prev; node != *head; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap_prev(head, &end, &node);
				print_list((const listint_t *)*head);
				sorted = false;
			}
		}
	}
}
