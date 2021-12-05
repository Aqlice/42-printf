/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:09:53 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:09:55 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_o_ll(t_list *p, va_list *arg)
{
	unsigned long long res;

	res = va_arg(*arg, long long);
	p->check = res;
	p->result = ft_itoa_base_ll(res, 8);
	if (p->dieze == 1)
		if (p->result[0] != '0')
		{
			p->tmp = p->result;
			p->result = ft_strjoin("0", p->result);
			free(p->tmp);
		}
}

void	get_o_l(t_list *p, va_list *arg)
{
	unsigned long res;

	res = va_arg(*arg, long);
	p->check = res;
	p->result = ft_itoa_base_ll(res, 8);
	if (p->dieze == 1)
		if (p->result[0] != '0')
		{
			p->tmp = p->result;
			p->result = ft_strjoin("0", p->result);
			free(p->tmp);
		}
}

void	get_o_hh(t_list *p, va_list *arg)
{
	unsigned char res;

	res = va_arg(*arg, int);
	p->check = res;
	p->result = ft_itoa_base_ll(res, 8);
	if (p->dieze == 1)
		if (p->result[0] != '0')
		{
			p->tmp = p->result;
			p->result = ft_strjoin("0", p->result);
			free(p->tmp);
		}
}

void	get_o_h(t_list *p, va_list *arg)
{
	unsigned short res;

	res = va_arg(*arg, int);
	p->check = res;
	p->result = ft_itoa_base_ll(res, 8);
	if (p->dieze == 1)
		if (p->result[0] != '0')
		{
			p->tmp = p->result;
			p->result = ft_strjoin("0", p->result);
			free(p->tmp);
		}
}

void	conv_o(t_list *p, va_list *arg)
{
	unsigned int res;

	if (p->ll == 1)
		get_o_ll(p, arg);
	else if (p->l == 1)
		get_o_l(p, arg);
	else if (p->hh == 1)
		get_o_hh(p, arg);
	else if (p->h == 1)
		get_o_h(p, arg);
	else
	{
		res = va_arg(*arg, int);
		p->result = ft_itoa_base_ll(res, 8);
		if (p->prec == 0 && res == 0)
			p->result = ft_strnew(1);
		if (p->dieze == 1)
			if (p->result[0] != '0')
			{
				p->tmp = p->result;
				p->result = ft_strjoin("0", p->result);
				free(p->tmp);
			}
	}
	handle_o(p);
}
