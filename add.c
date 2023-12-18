#include "monty.h"

/**
 * add_top - adds the top two elements of the stack
 * @head: A double pointer to the head of the stack
 * @line: line_number
 * Return: nothing
 */
void add_top(stack_t **head, unsigned int line)
{
	stack_t *s;
	int count = 0, sum;

	s = *head;

	while (s)
	{
		s = s->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	s = *head;
	sum = s->n + s->next->n;
	s->next->n = sum;
	*head = s->next;
	free(s);
}
