#include "monty.h"

/**
 * free_stack - deallocates a double linked list
 * @head: pointer to the top of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;

	while (head)
	{
		temp = head->next;

		free(head);
		head = temp;
	}
}
