#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int a, b, c;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = tmp->n;
	b = tmp->next->n;
	c = a + b;
	tmp->next->n = c;
	*stack = tmp->next;
	free(tmp);
}
