#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *st;

	st = malloc(sizeof(stack_t));
	if (st == NULL)
		return (malloc_error());

	st->n = STACK;
	st->prev = NULL;
	st->next = NULL;

	*stack = st;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to top (stack) or bottom (queue)
 *
 * Return: stack mode - STACK (0).
 *         queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

