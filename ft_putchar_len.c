/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:08:07 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:08:08 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, t_list *p)
{
	write(1, &c, 1);
	p->len++;
}

void	ft_putstr_len(char *str, t_list *p)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		ft_putchar_len(str[i], p);
		i++;
	}
}
