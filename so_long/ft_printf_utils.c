/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:49:33 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/15 15:13:04 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putnbr( long int n)
{
	long	nbr;
	size_t	i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		i += ft_putnbr(nbr / 10);
	i += ft_putchar((char)(nbr % 10 + '0'));
	return (i);
}

size_t	hexalow(unsigned long n)
{
	static size_t	i;
	const char		*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		hexalow(n / 16);
	}
	i += ft_putchar(hex[n % 16]);
	return (i);
}

size_t	hexahigh(unsigned long n)
{
	static size_t	i;
	const char		*hex;

	hex = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		hexahigh(n / 16);
	}
	i += ft_putchar(hex[n % 16]);
	return (i);
}

size_t	ft_p(unsigned long int p)
{
	size_t	j;

	j = 2;
	write(1, "0", 1);
	write(1, "x", 1);
	j += hexalow(p);
	return (j);
}
