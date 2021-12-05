/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:55:04 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:55:07 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_x_ll(t_list *p, va_list *arg)
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
	p->result = ft_itoa_base_ll(res, 16);
}

void	get_x_l(t_list *p, va_list *arg)
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
	p->result = ft_itoa_base_ll(res, 16);
}

void	get_x_hh(t_list *p, va_list *arg)
{
	char res;

	res = va_arg(*arg, int);
	p->check = res;
	if (res < 0)
	{
		p->sign = '-';
		res = -res;
	}
	else
		p->sign = '+';
	p->result = ft_itoa_base_ll(res, 16);
}

void	get_x_h(t_list *p, va_list *arg)
{
	short res;

	res = va_arg(*arg, int);
	p->check = res;
	if (res < 0)
	{
		p->sign = '-';
		res = -res;
	}
	else
		p->sign = '+';
	p->result = ft_itoa_base_ll(res, 16);
}

void	conv_x(t_list *p, va_list *arg)
{
	if (p->ll == 1)
		get_x_ll(p, arg);
	else if (p->l == 1)
		get_x_l(p, arg);
	else if (p->hh == 1)
		get_x_hh(p, arg);
	else if (p->h == 1)
		get_x_h(p, arg);
	else
		get_x(p, arg);
	if (p->prec == 0 && p->check == 0)
	{
		p->tmp = p->result;
		p->result = ft_strnew(1);
		free(p->tmp);
	}
	if (p->plus != 1)
		p->sign = 0;
	if (p->x == 1)
		ft_capitalize(p);
	handle_x(p);
}
