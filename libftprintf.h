/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:58:47 by nlaurids          #+#    #+#             */
/*   Updated: 2020/01/08 12:23:26 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *argslist, ...);
int		ft_ifcomb(const char *argslist, va_list ap, int flags[6]);
int		ft_ifcomb2(const char *argslist, va_list ap, int flags[6]);
void	ft_resetflags(int flags[6]);
void	ft_whichconv(const char *argslist, va_list ap, int flags[6]);
int		ft_ifconv(const char c);
int		ft_atoi2(const char *str);
int		ft_strlen(const char *arg);
int		ft_checknumsize(long n, int a);
int		ft_checkhexsize(unsigned long n);
void	ft_pchar(const char c, va_list ap, int flags[6]);
void	ft_pstring(va_list ap, int flags[6]);
void	ft_paddress(va_list ap, int flags[6]);
void	ft_paddress2(unsigned long arg, int len, int flags[6]);
void	ft_pint(const char c, va_list ap, int flags[6]);
void	ft_pint2(long arg, int len, int len2, int flags[6]);
void	ft_phex(const char c, va_list ap, int flags[6]);
void	ft_phex2(const char c, int arg, int len, int flags[6]);
void	ft_putchar(const char c, int flags[6]);
void	ft_putnbr(long arg, int flags[6]);
void	ft_puthex(unsigned int arg, const char c, int flags[6]);
void	ft_putaddress(unsigned long arg, int flags[6]);

#endif
