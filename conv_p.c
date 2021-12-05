#include "ft_printf.h"

void	conv_p(t_list *p, va_list *arg)
{
	void *z;
	long long unsigned int test;

	z = va_arg(*arg, void*);
	test = (unsigned long long)z;
	p->dieze = 1;
	p->result = ft_itoa_base_ll(test, 16);
	p->tmp = p->result;
	p->result = ft_strjoin("0x", p->result);
	free(p->tmp);
	conv_s(p);
}