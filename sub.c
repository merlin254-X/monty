#include "monty.h"

/**
 *  f_sub - subtraction
 *  @head: top of the stack
 *  @counter: line_number
 *  Return: nothing
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int diff, count;

	temp = *head;

	/*count the number of elements in  the stack*/
	for (count = 0; temp != NULL; count++)
		temp = temp->next;

	/*check if there are at least two elements in the block*/
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*perform subtraction on the top of two elements*/
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}
