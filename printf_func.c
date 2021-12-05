/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:15:39 by casautou          #+#    #+#             */
/*   Updated: 2019/02/14 20:15:40 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlenp(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_itoa_conv_long(char *str, char neg, uintmax_t nu)
{
	int i;

	i = 0;
	while (nu > 0)
	{
		str[i] = (nu % 10) + 48;
		nu = nu / 10;
		i++;
	}
	if (neg == '-')
	{
		str[i] = neg;
		str[i + 1] = 0;
	}
	else
		str[i] = 0;
	return (str);
}

char	*ft_itoa_long(uintmax_t n)
{
	char			*str;
	char			neg;

	neg = 0;
	if (n < 0)
	{
		neg = '-';
		n = -n;
	}
	str = (char*)malloc(sizeof(char) * 40);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_itoa_conv_long(str, neg, n);
	return (ft_strrev(str));
}

char	*ft_itoa_conv_base_ll(char *str, char neg, long long nu, int base)
{
	int i;

	i = 0;
	while (nu > 0)
	{
		if (nu % base >= 10)
		{
			str[i] = (nu % base) + 48 + 7 + 32;
			nu = nu / base;
			i++;
		}
		else
		{
			str[i] = (nu % base) + 48;
			nu = nu / base;
			i++;
		}
	}
	if (neg == '-')
	{
		str[i] = neg;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa_base_ll(long long n, int b)
{
	char			*str;
	char			neg;
	long long		nu;

	neg = 0;
	nu = n;
	if (n < 0)
	{
		neg = '-';
		nu = -n;
	}
	str = (char*)malloc(sizeof(char) * 40);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_itoa_conv_base_ll(str, neg, nu, b);
	return (ft_strrev(str));
}
