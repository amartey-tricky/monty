#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	free(tmp);
}
