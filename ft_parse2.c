/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:37:32 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/06 17:28:06 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pint(const char c, va_list ap, int flags[6])
{
	long	arg;
	int		len;
	int		len2;

	if (c == 'u')
		arg = va_arg(ap, unsigned int);
	else
		arg = va_arg(ap, int);
	len2 = flags[4] - ft_checknumsize(arg, 0);
	if (flags[4] > ft_checknumsize(arg, 0))
	{
		if (arg > 0)
			len = flags[2] - flags[4];
		else
			len = flags[2] - len2 - ft_checknumsize(arg, 19);
	}
	else
		len = flags[2] - ft_checknumsize(arg, 19);
	if (!flags[1] && flags[2] && flags[3])
		while (len-- > 0)
			ft_putchar(' ', flags);
	if (((flags[0] && !flags[3]) || flags[3]) && arg < 0)
		ft_putchar('-', flags);
	ft_pint2(arg, len, len2, flags);
}

void	ft_pint2(long arg, int len, int len2, int flags[6])
{
	if (!flags[1] && flags[2] && !flags[3])
	{
		while (len-- > 0)
		{
			if (flags[0])
				ft_putchar('0', flags);
			else
				ft_putchar(' ', flags);
		}
	}
	if (flags[3])
		while (len2-- > 0)
			ft_putchar('0', flags);
	if (!arg && flags[3] && !flags[4])
	{
		if (flags[2])
			ft_putchar(' ', flags);
	}
	else
		ft_putnbr(arg, flags);
	if (flags[1])
		while (len-- > 0)
			ft_putchar(' ', flags);
}

void	ft_phex(const char c, va_list ap, int flags[6])
{
	unsigned int	arg;
	int				len;
	int				len2;

	arg = va_arg(ap, unsigned int);
	if (flags[4] > ft_checkhexsize(arg))
		len = flags[2] - flags[4];
	else
		len = flags[2] - ft_checkhexsize(arg);
	len2 = flags[4] - ft_checkhexsize(arg);
	if (!flags[1] && flags[2] && flags[3])
		while (len-- > 0)
			ft_putchar(' ', flags);
	if (!flags[0] && !flags[1] && flags[2] && !flags[3])
		while (len-- > 0)
			ft_putchar(' ', flags);
	if (flags[0] && !flags[1] && flags[2] && !flags[3])
		while (len-- > 0)
			ft_putchar('0', flags);
	if (flags[3])
		while (len2-- > 0)
			ft_putchar('0', flags);
	ft_phex2(c, arg, len, flags);
}

void	ft_phex2(const char c, int arg, int len, int flags[6])
{
	if (!arg && flags[3] && !flags[4])
	{
		if (flags[2])
			ft_putchar(' ', flags);
	}
	else
		ft_puthex(arg, c, flags);
	if (flags[1])
		while (len-- > 0)
			ft_putchar(' ', flags);
}
