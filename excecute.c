#include "monty.h"
/**
 * execute - runs the given opcode
 * @stack: pointer to the head of the stack
 * @counter: line number
 * @file: pointer to the monty file
 * @content: line content
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", NULL}, {"pall", NULL}, {"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"pchar", NULL},
		{"pstr", NULL},
		{"rotl", NULL},
		{"rotr", NULL},
		{"queue", NULL},
		{"stack", NULL},
		{NULL, NULL}

	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, "\n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unkmown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
