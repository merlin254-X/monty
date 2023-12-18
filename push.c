#include "monty.h"

/**
 * my_push - append node to the stack
 * @head: stack top
 * @counter: line_number
 * Return: nothing
 */
void my_push(stack_t **head, unsigned int counter)
{
	int n, i = 0, flag = 0;

	if (bus.arg)
	{
		/*handle the case where the number is negative*/
		if (bus.arg[i] == '-')
			i++;
		/*validate each character of the argument*/
		while (bus.arg[i] != '\0')
		{
			if (bus.arg[i] < '0' || bus.arg[i] > '9')
				flag = 1;
			i++;
		}
		/*if any non_digit character is found, print an error message and exit*/
		if (flag)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*if there is no argument, print an error message and exit*/
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*convert the argument to an integer using atoi*/
	n = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
