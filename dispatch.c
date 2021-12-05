/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:49:27 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:49:32 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch(t_list *p, va_list *arg)
{
	if (*p->fmt == 'c')
		conv_c(p, arg);
	else if (*p->fmt == 's')
		conv_str(p, arg);
	else if (*p->fmt == 'p')
		conv_p(p, arg);
	else if (*p->fmt == 'd')
		conv_di(p, arg);
	else if (*p->fmt == 'i')
		conv_di(p, arg);
	else if (*p->fmt == 'o')
		conv_o(p, arg);
	else if (*p->fmt == 'u')
		conv_u(p, arg);
	else if (*p->fmt == 'x' || *p->fmt == 'X')
	{
		if (*p->fmt == 'X')
			p->x = 1;
		conv_x(p, arg);
	}
	else if (*p->fmt == '%')
		conv(p);
	else
		p->fmt--;
}
