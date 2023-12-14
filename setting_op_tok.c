#include "monty.h"

/**
 * set_op_tok_error - Sets the last element of op_toks to be an error code.
 * @er_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int er_code)
{
	int toklen = 0, i = 0;
	char *exit_str = NULL;
	char **nwtok = NULL;

	toklen = token_arr_len();
	nwtok = malloc(sizeof(char *) * (toklen + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toklen)
	{
		nwtok[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(er_code);
	if (!exit_str)
	{
		free(nwtok);
		malloc_error();
		return;
	}
	nwtok[i++] = exit_str;
	nwtok[i] = NULL;
	free(op_toks);
	op_toks = nwtok;
}

