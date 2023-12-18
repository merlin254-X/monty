#include "monty.h"

/**
 * f_mul - multiply the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: nothing
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *top;

	int size = 0;

	int result;

	top = *head;

	while (top)
	{
		top = top->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	result = top->next->n * top->n;
	top->next->n = result;
	*head = top->next;
	free(top);

}
