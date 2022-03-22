/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:49:20 by sdarci            #+#    #+#             */
/*   Updated: 2021/12/08 17:18:49 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	func1(const char *fmt1, va_list p)
{
	int	i;

	i = 0;
	if (*fmt1 == 'u')
		return (ft_putnbr(va_arg(p, unsigned int)));
	if (*fmt1 == '%')
		return (ft_putchar('%'));
	if (*fmt1 == 'd' || *fmt1 == 'i')
		return (ft_putnbr(va_arg(p, int)));
	if (*fmt1 == 's')
		return (ft_putstr(va_arg(p, char *)));
	if (*fmt1 == 'c')
		return (ft_putchar(va_arg(p, int)));
	if (*fmt1 == 'p')
		return (ft_p(va_arg(p, unsigned long int)));
	if (*fmt1 == 'x')
		return (hexalow(va_arg(p, unsigned int)));
	if (*fmt1 == 'X')
		return (hexahigh(va_arg(p, unsigned int)));
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	p;
	int		d;

	d = 0;
	va_start(p, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			d += func1(++fmt, p);
			fmt++;
		}
		else
		{
			write(1, &*fmt++, 1);
			d++;
		}
	}
	va_end(p);
	return (d);
}
