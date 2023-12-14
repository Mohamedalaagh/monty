#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

char **op_toks;
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln_num);
} instruction_t;

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int er_code);

void monty_push(stack_t **stack, unsigned int ln_num);
void monty_pall(stack_t **stack, unsigned int ln_num);
void monty_pint(stack_t **stack, unsigned int ln_num);
void monty_pop(stack_t **stack, unsigned int ln_num);
void monty_swap(stack_t **stack, unsigned int ln_num);
void monty_add(stack_t **stack, unsigned int ln_num);
void monty_nop(stack_t **stack, unsigned int ln_num);
void monty_sub(stack_t **stack, unsigned int ln_num);
void monty_div(stack_t **stack, unsigned int ln_num);
void monty_mul(stack_t **stack, unsigned int ln_num);
void monty_mod(stack_t **stack, unsigned int ln_num);
void monty_pchar(stack_t **stack, unsigned int ln_num);
void monty_pstr(stack_t **stack, unsigned int ln_num);
void monty_rotl(stack_t **stack, unsigned int ln_num);
void monty_rotr(stack_t **stack, unsigned int ln_num);
void monty_stack(stack_t **stack, unsigned int ln_num);
void monty_queue(stack_t **stack, unsigned int ln_num);

char **strtow(char *st, char *dl);
char *get_int(int n);

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int ln_num);
int no_int_error(unsigned int ln_num);
int pop_error(unsigned int ln_num);
int pint_error(unsigned int ln_num);
int short_stack_error(unsigned int ln_num, char *op);
int div_error(unsigned int ln_num);
int pchar_error(unsigned int ln_num, char *message);

#endif

