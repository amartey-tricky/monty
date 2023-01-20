#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int a, b = 0, flag = 0;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			b++;
		for (; global.arg[b]; b++)
		{
			if (global.arg[b] < '0' || global.arg[b] > '9')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		a = atoi(global.arg);
		if (global.change == STACK)
			add_dnodeint(stack, a);
		else
			add_dnodeint_end(stack, a);
	}
}

/**
 * op_pall - prints all the values on the stack,
 *           starting from the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
