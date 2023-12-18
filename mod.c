#include "monty.h"

/**
 * f_mod - calculates the remainder of the division of the second top
 * element of the stack by the top element of the stack
 * @head: pointer to the stack head
 * @counter: line_number
 * Return: nothing
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, result;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
