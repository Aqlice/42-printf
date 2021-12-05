/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:56:41 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:56:43 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_list	p;

	va_start(arg, format);
	p.len = 0;
	init_printf(format, &p);
	launch_printf(&p, &arg);
	va_end(arg);
	return (p.len);
}
