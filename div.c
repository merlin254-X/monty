#include "monty.h"

/**
 * f_div - performs division on the top two elements of the stack
 * @head: pointer to the stack head
 * @counter: line number
 * Return: nothing
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int size = 0, result;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		size++;
	}

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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

	result = temp->next->n / temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
