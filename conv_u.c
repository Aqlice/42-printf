/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:54:02 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:54:06 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_u_ll(t_list *p, va_list *arg)
{
	unsigned long long res;

	res = va_arg(*arg, unsigned long long);
	p->plus = 0;
	p->check = res;
	p->result = ft_itoa_long(res);
}

void	get_u_l(t_list *p, va_list *arg)
{
	unsigned long res;

	res = va_arg(*arg, unsigned long);
	p->plus = 0;
	p->check = res;
	p->result = ft_itoa_long(res);
}

void	get_u_hh(t_list *p, va_list *arg)
{
	unsigned char res;

	res = va_arg(*arg, int);
	p->plus = 0;
	p->check = res;
	p->result = ft_itoa_long(res);
}

void	get_u_h(t_list *p, va_list *arg)
{
	unsigned short res;

	res = va_arg(*arg, int);
	p->check = res;
	p->plus = 0;
	p->result = ft_itoa_long(res);
}

void	conv_u(t_list *p, va_list *arg)
{
	unsigned int res;

	if (p->ll == 1)
		get_u_ll(p, arg);
	else if (p->l == 1)
		get_u_l(p, arg);
	else if (p->hh == 1)
		get_u_hh(p, arg);
	else if (p->h == 1)
		get_u_h(p, arg);
	else
	{
		res = va_arg(*arg, int);
		p->plus = 0;
		p->result = ft_itoa_long(res);
	}
	if (p->prec == 0 && p->check == 0)
		p->error = 1;
	handle_u(p);
}
