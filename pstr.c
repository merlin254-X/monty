#include "monty.h"

/**
 * f_pstr - displays the string from the top of the stack, followed by new line
 * @head: pointer to the top of the stack
 * @counter: line number
 * Return: nothing
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;
	current = *head;

	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
