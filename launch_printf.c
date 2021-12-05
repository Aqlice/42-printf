/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:57:16 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:57:18 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	launch_printf(t_list *p, va_list *arg)
{
	while (*p->fmt)
	{
		while (*p->fmt && *p->fmt != '%')
		{
			ft_putchar_len(*p->fmt, p);
			p->fmt++;
		}
		if (*p->fmt == '%')
		{
			p->fmt++;
			check_flags(p);
			dispatch(p, arg);
			init_flags(p);
			p->fmt++;
		}
	}
}
