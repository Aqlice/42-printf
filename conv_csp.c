/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:18:59 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:19:01 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*conv_s_prec(t_list *p)
{
	char *tmp;

	if (p->prec > ft_strlenp(p->result))
		return (p->result);
	tmp = p->result;
	p->result = ft_strndup(p->result, p->prec);
	free(tmp);
	return (p->result);
}

static char	*conv_s_width(t_list *p)
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

static char	*conv_s_width_minus(t_list *p)
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

static char	*conv_s_width_zero(t_list *p)
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

void		conv_s(t_list *p)
{
	if (p->prec != -1)
		p->result = conv_s_prec(p);
	if (p->width != -1 && p->width > ft_strlenp(p->result))
	{
		if (p->minus == 1)
			p->result = conv_s_width_minus(p);
		else if (p->zero == 1)
			p->result = conv_s_width_zero(p);
		else
			p->result = conv_s_width(p);
	}
	if (p->sign == '-' || p->plus == 1)
		ft_putchar_len(p->sign, p);
	ft_putstr_len(p->result, p);
	free(p->result);
}
