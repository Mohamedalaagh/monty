#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int ln_num);
void monty_rotr(stack_t **stack, unsigned int ln_num);
void monty_stack(stack_t **stack, unsigned int ln_num);
void monty_queue(stack_t **stack, unsigned int ln_num);

void monty_rotl(stack_t **stack, unsigned int ln_num)
{
	stack_t *top, *b;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	b = (*stack)->next;
	while (b->next != NULL)
		b = b->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	b->next = top;
	top->next = NULL;
	top->prev = b;

	(void)ln_num;
}

void monty_rotr(stack_t **stack, unsigned int ln_num)
{
	stack_t *top, *b;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	b = (*stack)->next;
	while (b->next != NULL)
		b = b->next;

	b->prev->next = NULL;
	(*stack)->next = b;
	b->prev = *stack;
	b->next = top;
	top->prev = b;

	(void)ln_num;
}

void monty_stack(stack_t **stack, unsigned int ln_num)
{
	(*stack)->n = STACK;
	(void)ln_num;
}

void monty_queue(stack_t **stack, unsigned int ln_num)
{
	(*stack)->n = QUEUE;
	(void)ln_num;
}

