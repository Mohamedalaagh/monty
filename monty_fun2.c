#include "monty.h"

void monty_add(stack_t **stack, unsigned int ln_num);
void monty_sub(stack_t **stack, unsigned int ln_num);
void monty_div(stack_t **stack, unsigned int ln_num);
void monty_mul(stack_t **stack, unsigned int ln_num);
void monty_mod(stack_t **stack, unsigned int ln_num);

void monty_add(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, ln_num);
}

void monty_sub(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, ln_num);
}

void monty_div(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(ln_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, ln_num);
}

void monty_mul(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, ln_num);
}

void monty_mod(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(ln_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, ln_num);
}

