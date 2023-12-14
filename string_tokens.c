#include <stdlib.h>

char **strtow(char *st, char *dl);
int is_delim(char ch, char *dl);
int get_word_length(char *st, char *dl);
int get_word_count(char *st, char *dl);
char *get_next_word(char *st, char *dl);

char **strtow(char *st, char *dl)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (st == NULL || !*st)
		return (NULL);
	wc = get_word_count(st, dl);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(st, dl);
		if (is_delim(*st, dl))
		{
			st = get_next_word(st, dl);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(st + n);
			n++;
		}
		words[i][n] = '\0';
		st = get_next_word(st, dl);
		i++;
	}
	words[i] = NULL;
	return (words);
}

int is_delim(char ch, char *dl)
{
	int i = 0;

	while (dl[i])
	{
		if (dl[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int get_word_length(char *st, char *dl)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(st + i))
	{
		if (is_delim(st[i], dl))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(st[i], dl))
			break;
		i++;
	}
	return (wLen);
}

int get_word_count(char *st, char *dl)
{
	int wc = 0, pending = 1, i = 0;

	while (*(st + i))
	{
		if (is_delim(st[i], dl))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

char *get_next_word(char *st, char *dl)
{
	int pending = 0;
	int i = 0;

	while (*(st + i))
	{
		if (is_delim(st[i], dl))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (st + i);
}

