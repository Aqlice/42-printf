/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:12:37 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:12:38 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_di_prec(t_list *p)
{
	char	*s;
	int		stock;
	int		i;

	i = 0;
	stock = ft_strlenp(p->result);
	if (p->sign == '-' || p->plus == 1)
		p->prec++;
	if (p->prec < stock)
		return (p->result);
	s = ft_strnew(p->prec + 1);
	s = handle_di_prec_2(p, s, i, stock);
	p->zero = 0;
	p->tmp = p->result;
	p->result = ft_strjoin(s, p->result);
	free(p->tmp);
	free(s);
	return (p->result);
}

static char	*handle_di_width(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	p->tmp = p->result;
	fill = p->width - (ft_strlenp(p->result));
	new = ft_strnew(p->width + 1);
	p->space = 0;
	new = handle_di_width_2(p, new, fill, i);
	return (new);
}

static char	*handle_di_width_minus(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	fill = p->width - (ft_strlenp(p->result)) - (p->space);
	new = ft_strnew(p->width);
	new = handle_di_width_minus_2(p, new, fill, i);
	return (new);
}

static char	*handle_di_width_zero(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	fill = p->width - (ft_strlenp(p->result)) + 1 - p->space;
	new = ft_strnew(p->width);
	new = handle_di_width_zero_2(p, new, fill, i);
	return (new);
}

void	handle_di(t_list *p)
{
	if (p->prec != -1 && p->prec != 0)
		p->result = handle_di_prec(p);
	if (p->width != -1 && p->width > ft_strlenp(p->result))
	{
		if (p->minus == 1)
			p->result = handle_di_width_minus(p);
		else if (p->zero == 1)
			p->result = handle_di_width_zero(p);
		else
			p->result = handle_di_width(p);
	}
	if (p->space == 1 && p->sign != '-')
		ft_putchar_len(' ', p);
	if (p->plus == 1)
		ft_putchar_len(p->sign, p);
	ft_putstr_len(p->result, p);
	free(p->result);
}
