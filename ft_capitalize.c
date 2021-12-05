#include "ft_printf.h"

void	ft_capitalize(t_list *p)
{
	char *s;

	s = p->result;
	while (*p->result)
	{
		if (*p->result >= 'a' && *p->result <= 'z')
			*p->result = *p->result - 32;
		p->result++;
	}
	p->result = s;
}
