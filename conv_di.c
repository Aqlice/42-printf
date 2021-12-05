/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:07:33 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:07:35 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_di_ll(t_list *p, va_list *arg)
{
	long long res;

	res = va_arg(*arg, long long);
	p->check = res;
	if (res < 0)
	{
		p->sign = '-';
		res = -res;
	}
	else
		p->sign = '+';
	p->result = ft_itoa_long(res);
}

void	get_di_l(t_list *p, va_list *arg)
{
	long res;

	res = va_arg(*arg, long);
	p->check = res;
	if (res < 0)
	{
		p->sign = '-';
		res = -res;
	}
	else
		p->sign = '+';
	p->result = ft_itoa_long(res);
}

void	get_di_hh(t_list *p, va_list *arg)
{
	char	res;
	int		rez;

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
	p->result = ft_itoa(rez);
}

void	get_di_h(t_list *p, va_list *arg)
{
	short	res;
	int		rez;

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
	p->result = ft_itoa(rez);
}

void	conv_di(t_list *p, va_list *arg)
{
	if (p->ll == 1)
		get_di_ll(p, arg);
	else if (p->l == 1)
		get_di_l(p, arg);
	else if (p->hh == 1)
		get_di_hh(p, arg);
	else if (p->h == 1)
		get_di_h(p, arg);
	else
		get_di_int(p, arg);
	get_di_sign(p);
	handle_di(p);
}
