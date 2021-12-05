/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:51:14 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 19:51:24 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_list *p)
{
	p->minus = 0;
	p->plus = 0;
	p->zero = 0;
	p->space = 0;
	p->dieze = 0;
	p->star = 0;
	p->width = -1;
	p->prec = -1;
	p->l = 0;
	p->ll = 0;
	p->h = 0;
	p->hh = 0;
	p->sprec = -1;
	p->boucle = 0;
	p->check = -1;
}
