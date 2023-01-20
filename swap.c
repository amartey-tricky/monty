#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = tmp->n;
	b = tmp->next->n;
	tmp->n = b;
	tmp->next->n = a;
}
