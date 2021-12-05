#include "ft_printf.h"

void	get_di_int(t_list *p, va_list *arg)
{
	int				res;
	unsigned int	rez;

	res = va_arg(*arg, int);
	p->check = res;
	if (res < 0)
	{
		p->sign = '-';
		rez = -res;
	}
	else
	{
		p->sign = '+';
		rez = res;
	}
	p->result = ft_itoa_long(rez);
}

void	get_di_sign(t_list *p)
{
	if (p->sign == '-' && p->zero == 0 && p->minus == 0 && p->prec == -1)
	{
		p->plus = 0;
		if (!(p->result[0] == '-'))
		{
			p->tmp = p->result;
			p->result = ft_strjoin("-", p->result);
			free(p->tmp);
		}
	}
	if (p->prec == 0 && p->check == 0)
	{
		p->tmp = p->result;
		p->result = ft_strnew(1);
		free(p->tmp);
	}
}

void	get_x(t_list *p, va_list *arg)
{
	unsigned int res;

	res = va_arg(*arg, int);
	p->check = res;
	if (res == 0)
		p->dieze = 0;
	p->result = ft_itoa_base_ll(res, 16);
	if (p->dieze == 1 && p->zero != 1 && p->prec == -1)
	{
		p->tmp = p->result;
		p->result = ft_strjoin("0x", p->result);
		p->dieze = 0;
		free(p->tmp);
	}
}

char	*handle_di_width_minus_2(t_list *p, char *new, int fill, int i)
{
	p->tmp = p->result;
	if (p->sign == '-' || (p->plus == 1 && p->sign == '+'))
	{
		new[i] = p->sign;
		fill--;
		i++;
		p->plus = 0;
	}
	while (*p->result)
	{
		new[i] = *p->result;
		i++;
		p->result++;
	}
	while (fill-- > 0)
	{
		new[i] = ' ';
		i++;
	}
	free(p->tmp);
	return (new);
}

char	*handle_di_width_zero_2(t_list *p, char *new, int fill, int i)
{
	p->tmp = p->result;
	if (p->sign == '-' || (p->plus == 1 && p->sign == '+'))
	{
		new[i] = p->sign;
		fill--;
		i++;
		p->plus = 0;
	}
	while (fill-- > 1)
	{
		new[i] = '0';
		i++;
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