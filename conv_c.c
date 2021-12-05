/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:57:48 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:57:50 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_list *p, va_list *arg)
{
	char c;

	c = va_arg(*arg, int);
	if (p->minus == 1)
	{
		ft_putchar_len(c, p);
		while (p->width-- > 1)
			ft_putchar_len(' ', p);
	}
	else if (p->width != -1)
	{
		if (p->zero == 1)
			while (p->width-- > 1)
				ft_putchar_len('0', p);
		else
			while (p->width-- > 1)
				ft_putchar_len(' ', p);
		ft_putchar_len(c, p);
	}
	else
		ft_putchar_len(c, p);
}
