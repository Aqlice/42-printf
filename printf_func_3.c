#include "ft_printf.h"

char	*handle_di_prec_2(t_list *p, char *s, int i, int stock)
{
    if (p->sign == '-' || p->plus == 1)
	{
		s[0] = p->sign;
		i = 1;
		p->prec--;
		p->plus = 0;
		p->sign = 0;
	}
	while (p->prec - stock > 0)
	{
		s[i] = '0';
		i++;
		p->prec--;
	}
    return (s);
}

char	*handle_di_width_2(t_list *p, char *new, int fill, int i)
{
	while (fill-- > 0)
	{
		new[i] = ' ';
		i++;
	}
	if (p->plus == 1)
	{
		new[i] = '+';
		i++;
		p->plus = 0;
	}
	while (*p->result)
	{
		new[i] = *p->result;
		i++;
		p->result++;
	}
	free(p->tmp);
	return (new);
}