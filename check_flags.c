/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:47:50 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:47:54 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_boucle(t_list *p)
{
	while (p->fmt && (*p->fmt == 'l' || *p->fmt == 'h'))
	{
		p->boucle = 1;
		p->fmt++;
	}
	if (p->boucle == 1)
	{
		p->l = 0;
		p->ll = 0;
		p->h = 0;
		p->hh = 0;
	}
}

void	check_type(t_list *p)
{
	if (*p->fmt == 'l')
	{
		p->fmt++;
		if (*p->fmt == 'l')
		{
			p->ll = 1;
			p->fmt++;
		}
		p->l = 1;
	}
	if (*p->fmt == 'h')
	{
		p->fmt++;
		if (*p->fmt == 'h')
		{
			p->hh = 1;
			p->fmt++;
		}
		p->h = 1;
	}
	check_boucle(p);
}

void	check_precision(t_list *p)
{
	int stock;

	stock = 0;
	if (*p->fmt == '*')
	{
		p->star = 1;
		p->fmt++;
	}
	while (*p->fmt && *p->fmt <= '9' && *p->fmt >= '0')
	{
		stock = stock * 10 + *p->fmt - 48;
		p->fmt++;
	}
	p->prec = stock;
	check_type(p);
}

void	check_width(t_list *p)
{
	int stock;

	stock = -1;
	if (*p->fmt && *p->fmt <= '9' && *p->fmt >= '0')
	{
		stock = 0;
		while (*p->fmt && *p->fmt <= '9' && *p->fmt >= '0')
		{
			stock = stock * 10 + *p->fmt - 48;
			p->fmt++;
		}
	}
	p->width = stock;
	if (p->width < 1)
		p->zero = 0;
	if (*p->fmt == '.')
	{
		p->fmt++;
		check_precision(p);
	}
	else
	{
		p->prec = -1;
		check_type(p);
	}
}

void	check_flags(t_list *p)
{
	while (*p->fmt && (*p->fmt == '-' || *p->fmt == '+' || *p->fmt == '0'
	|| *p->fmt == ' ' || *p->fmt == '#'))
	{
		if (*p->fmt == '-')
			p->minus = 1;
		if (*p->fmt == '+')
			p->plus = 1;
		if (*p->fmt == '0')
			p->zero = 1;
		if (*p->fmt == ' ')
			p->space = 1;
		if (*p->fmt == '#')
			p->dieze = 1;
		p->fmt++;
	}
	if (p->plus == 1)
		p->space = 0;
	if (p->minus == 1)
		p->zero = 0;
	check_width(p);
}
