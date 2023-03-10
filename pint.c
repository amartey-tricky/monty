#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack,
 * 		     followed by a new line
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
