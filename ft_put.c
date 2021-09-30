/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:43:14 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/06 17:28:08 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(const char c, int flags[6])
{
	write(1, &c, 1);
	flags[5]++;
}

void	ft_putnbr(long arg, int flags[6])
{
	long l;

	l = arg;
	if (l < 0)
	{
		l = l * (-1);
		if (!flags[0] && !flags[3])
			ft_putchar('-', flags);
	}
	if (l > 9)
		ft_putnbr(l / 10, flags);
	ft_putchar(l % 10 + '0', flags);
}

void	ft_puthex(unsigned int arg, const char c, int flags[6])
{
	unsigned int	rem;
	int				i;
	char			hexadecimal[16];

	i = 0;
	if (!arg)
		ft_putchar('0', flags);
	while (arg)
	{
		rem = arg % 16;
		if (rem < 10)
			hexadecimal[i++] = 48 + rem;
		else
		{
			if (c == 'X')
				hexadecimal[i++] = 55 + rem;
			else
				hexadecimal[i++] = 87 + rem;
		}
		arg = arg / 16;
	}
	while (i > 0)
		ft_putchar(hexadecimal[--i], flags);
}

void	ft_putaddress(unsigned long arg, int flags[6])
{
	unsigned long	rem;
	int				i;
	char			hexadecimal[32];

	i = 0;
	if (!arg)
		ft_putchar('0', flags);
	while (arg)
	{
		rem = arg % 16;
		if (rem < 10)
			hexadecimal[i++] = 48 + rem;
		else
			hexadecimal[i++] = 87 + rem;
		arg = arg / 16;
	}
	while (i > 0)
		ft_putchar(hexadecimal[--i], flags);
}
