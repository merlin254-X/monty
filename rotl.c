#include "monty.h"

/**
 * f_rotl - moves the first element to the end of the stack
 * @head: pointer to the top of the stack
 * @counter: line_number
 * Return: nothing
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *first = *head, *last;

	if (first == NULL || first->next == NULL)
	{
		return;
	}
	last = first->next;
	last->prev = NULL;

	while (first->next != NULL)
	{
		first = first->next;
	}
	first->next = *head;
	(*head)->next = NULL;
	(*head)->prev = first;
	*head = last;
}
