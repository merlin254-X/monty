#include "monty.h"

/**
 * f_queue - displays the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - append node to the tail stack
 * @n: head of the stack
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}

	new_node->n = n;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}

	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
