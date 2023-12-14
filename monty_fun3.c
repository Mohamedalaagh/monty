#include "monty.h"

void monty_nop(stack_t **stack, unsigned int ln_num);
void monty_pchar(stack_t **stack, unsigned int ln_num);
void monty_pstr(stack_t **stack, unsigned int ln_num);

void monty_nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}

void monty_pchar(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(ln_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(ln_num, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

void monty_pstr(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)ln_num;
}

