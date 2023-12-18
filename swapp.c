#include "monty.h"

/**
 * f_swap - swaps the first two elements of the stack
 * @stack: stack head
 * @line: line number
 * Return: nothing
 */
void f_swap(stack_t **stack, unsigned int line)
{
	stack_t *s;
	int count = 0, temp;

	s = *stack;

	/*get the number of elements in the stack*/
	while (s)
	{
		s = s->next;
		count++;
	}

	/*make sure there are at least two elements i the stack*/
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/*swap the values of the first two elements*/
	s = *stack;
	temp = s->n;
	s->n = s->next->n;
	s->next->n = temp;
}
