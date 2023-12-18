#include "monty.h"

/**
 * print_stack - prints the stack
 * @top: top of the neck
 * @line_number: not used
 * Return: nothing
 */
void print_stack(stack_t **top, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *top;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
