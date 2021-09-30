/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:04:14 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/07 13:03:23 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ifcomb2(const char *argslist, va_list ap, int flags[6])
{
	while (*argslist >= '0' && *argslist <= '9')
		argslist++;
	if (*argslist == '.')
	{
		flags[3] = 1;
		argslist++;
	}
	if (*argslist >= '0' && *argslist <= '9')
		flags[4] = ft_atoi2(argslist);
	if (*argslist == '*')
		flags[4] = va_arg(ap, int);
	if (flags[4] < 0)
	{
		flags[3] = 0;
		if (*argslist != '*')
		{
			flags[1] = 1;
			flags[2] = flags[4] * (-1);
		}
	}
	while ((*argslist >= '0' && *argslist <= '9') || *argslist == '*')
		argslist++;
	return (ft_ifconv(*argslist));
}

int		ft_ifcomb(const char *argslist, va_list ap, int flags[6])
{
	while (*argslist == '0')
	{
		flags[0] = 1;
		argslist++;
	}
	if (*argslist == '-')
		while (*argslist == '-')
		{
			argslist++;
			flags[1] = 1;
		}
	if (*argslist == '*')
	{
		flags[2] = va_arg(ap, int);
		argslist++;
	}
	if (*argslist >= '0' && *argslist <= '9')
		flags[2] = ft_atoi2(argslist);
	if (flags[2] < 0)
	{
		flags[0] = 0;
		flags[1] = 1;
		flags[2] = flags[2] * (-1);
	}
	return (ft_ifcomb2(argslist, ap, flags));
}

int		ft_printf(const char *argslist, ...)
{
	va_list	ap;
	int		flags[6];

	flags[5] = 0;
	va_start(ap, argslist);
	while (*argslist)
	{
		if (*argslist == '%')
		{
			argslist++;
			ft_resetflags(flags);
			if (ft_ifcomb(argslist, ap, flags))
			{
				while (!ft_ifconv(*argslist))
					argslist++;
				ft_whichconv(argslist++, ap, flags);
			}
			else
				return (-1);
		}
		else
			ft_putchar(*argslist++, flags);
	}
	va_end(ap);
	return (flags[5]);
}
