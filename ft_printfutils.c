/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:55:09 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/08 12:26:27 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ifconv(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_whichconv(const char *argslist, va_list ap, int flags[6])
{
	if (*argslist == 'c' || *argslist == '%')
		ft_pchar(*argslist, ap, flags);
	if (*argslist == 's')
		ft_pstring(ap, flags);
	if (*argslist == 'p')
		ft_paddress(ap, flags);
	if (*argslist == 'd' || *argslist == 'i' || *argslist == 'u')
		ft_pint(*argslist, ap, flags);
	if (*argslist == 'x' || *argslist == 'X')
		ft_phex(*argslist, ap, flags);
}

void	ft_resetflags(int flags[6])
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
}
