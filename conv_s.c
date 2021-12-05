/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:25:43 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:25:45 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_str(t_list *p, va_list *arg)
{
	char *s;

	s = va_arg(*arg, char*);
	if (s == NULL)
		s = "(null)";
	if (!(p->result = ft_strdup(s)))
		return ;
	p->dieze = 0;
	conv_s(p);
}

void	conv(t_list *p)
{
	p->result = ft_strdup("%");
	if (p->prec == 0)
		p->prec = -1;
	conv_s(p);
}
