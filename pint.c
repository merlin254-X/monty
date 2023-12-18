#include "monty.h"

/**
 * f_print - prints the peak
 * @head: stack peak
 * @counter: line_number
 * Return: nothing
 */
void f_print(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack vacant\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
