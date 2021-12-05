/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:23:00 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:23:01 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_o_prec(t_list *p)
{
	char	*tmp;
	int		stock;
	char	*new;
	int		i;

	i = 0;
	stock = ft_strlenp(p->result);
	if (p->prec < ft_strlenp(p->result))
		return (p->result);
	tmp = p->result;
	stock = p->prec - stock;
	new = ft_strnew(p->prec + 1);
	while (stock-- > 0)
		new[i++] = '0';
	p->result = ft_strjoin(new, p->result);
	free(tmp);
	free(new);
	return (p->result);
}

static char	*handle_o_width(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	p->tmp = p->result;
	fill = p->width - (ft_strlenp(p->result));
	new = ft_strnew(p->width + 1);
	while (fill-- > 0)
	{
		new[i] = ' ';
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

static char	*handle_o_width_minus(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	p->tmp = p->result;
	fill = p->width - (ft_strlenp(p->result));
	new = ft_strnew(p->width + 1);
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

static char	*handle_o_width_zero(t_list *p)
{
	char	*new;
	int		fill;
	int		i;

	i = 0;
	p->tmp = p->result;
	fill = p->width - (ft_strlenp(p->result)) + 1;
	new = ft_strnew(p->width);
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

void		handle_o(t_list *p)
{
	p->plus = 0;
	if (p->prec != -1 && p->prec != 0)
		p->result = handle_o_prec(p);
	if (p->width != -1 && p->width > ft_strlenp(p->result))
	{
		if (p->minus == 1)
			p->result = handle_o_width_minus(p);
		else if (p->zero == 1)
			p->result = handle_o_width_zero(p);
		else
			p->result = handle_o_width(p);
	}
	ft_putstr_len(p->result, p);
	free(p->result);
}
