#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tail;

	tail = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (tail->next)
	{
		tail = tail->next;
	}

	tail->next = *head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	(*head)->prev = tail;
	(*head) = tail;
}
