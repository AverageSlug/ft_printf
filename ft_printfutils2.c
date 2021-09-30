/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:09:58 by nlaurids          #+#    #+#             */
/*   Updated: 2019/12/20 17:27:13 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi2(const char *str)
{
	unsigned long long	p;
	int					i;

	p = 0;
	i = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ')
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str++ == '-')
			i = -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (p > 9223372036854775807)
		{
			if (i == -1)
				return (0);
			else
				return (-1);
		}
		p = p * 10 + (*str++ - 48);
	}
	return (p * i);
}

int	ft_strlen(const char *arg)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

int	ft_checknumsize(long n, int a)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		if (a)
			i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int	ft_checkhexsize(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}
