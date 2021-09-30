/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:15:52 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/08 12:24:06 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pchar(const char c, va_list ap, int flags[6])
{
	int		len;
	char	t;

	len = flags[2] - 1;
	if (flags[2] && !flags[0] && !flags[1])
		while (len-- > 0)
			ft_putchar(' ', flags);
	if (flags[2] && flags[0] && !flags[1])
		while (len-- > 0)
			ft_putchar('0', flags);
	if (c == 'c')
		t = va_arg(ap, int);
	else
		t = c;
	ft_putchar(t, flags);
	if (flags[2] && !flags[0] && flags[1])
		while (len-- > 0)
			ft_putchar(' ', flags);
}

void	ft_pstring(va_list ap, int flags[6])
{
	char	*arg;
	int		len;
	int		len2;

	if (!(arg = va_arg(ap, char*)))
		arg = "(null)";
	len = ft_strlen(arg);
	if (flags[3] && flags[4] < len)
		len = flags[4];
	len2 = flags[2] - len;
	if (!flags[0] && !flags[1] && flags[2])
		while (len2-- > 0)
			ft_putchar(' ', flags);
	if (flags[0] && !flags[1] && flags[2])
		while (len2-- > 0)
			ft_putchar('0', flags);
	write(1, arg, len);
	flags[5] += len;
	if (flags[1] && flags[2])
		while (len2-- > 0)
			ft_putchar(' ', flags);
}

void	ft_paddress(va_list ap, int flags[6])
{
	unsigned long	arg;
	int				len;
	int				len2;

	arg = va_arg(ap, unsigned long);
	if (flags[4] > ft_checkhexsize(arg))
		len = flags[2] - 2;
	else
		len = flags[2] - ft_checkhexsize(arg) - 2;
	len2 = flags[4] - ft_checkhexsize(arg);
	if (!flags[1] && flags[2] && flags[3])
		while (len-- > 0)
			ft_putchar(' ', flags);
	if (!flags[0] && !flags[1] && flags[2] && !flags[3])
		while (len-- > 0)
			ft_putchar(' ', flags);
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	if (flags[0] && !flags[1] && flags[2] && !flags[3])
		while (len-- > 0)
			ft_putchar('0', flags);
	if (flags[3])
		while (len2-- > 0)
			ft_putchar('0', flags);
	ft_paddress2(arg, len, flags);
}

void	ft_paddress2(unsigned long arg, int len, int flags[6])
{
	if (!arg && flags[3] && !flags[4])
	{
		if (flags[2])
			ft_putchar(' ', flags);
	}
	else
		ft_putaddress(arg, flags);
	if (flags[1])
		while (len-- > 0)
			ft_putchar(' ', flags);
}
