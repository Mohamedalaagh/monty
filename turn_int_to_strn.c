#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
char *get_int(int num)
{
	unsigned int tm;
	int len = 0;
	long num_l = 0;
	char *ret;

	tm = _abs(num);
	len = get_numbase_len(tm, 10);

	if (num < 0 || num_l < 0)
		len++; /* negative sign */
	ret = malloc(len + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(tm, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
int get_numbase_len(unsigned int num, unsigned int base)
{
	int l = 1; /* all numbers contain at least one digit */

	while (num > base - 1)
	{
		l++;
		num /= base;
	}
	return (l);
}
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int r, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		r = num % base;
		if (r > 9) /* return lowercase ascii val representation */
			buff[i] = r + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = r + '0';
		num /= base;
		i--;
	}
}

