/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:38:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:39:23 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	sizestr(int n)
{
	size_t	s;

	s = 0;
	while (n)
	{
		n /= 10;
		s++;
	}
	return (s);
}

static int	minus(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = minus(n);
	if (size == 1)
		nbr = nbr * -1;
	size = size + sizestr(n);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (0);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}	
