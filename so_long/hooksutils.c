/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:47:32 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:47:33 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_win(t_map *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->mapspl[i])
	{
		j = 0;
		while (p->mapspl[i][j])
		{
			if (p->mapspl[i][j] == 'E')
				mlx_put_image_to_window(p->m2->mlx, p->m2->win, p->exitwon, \
				j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_sprite(t_map *m, int mv)
{
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->pll, \
	(m->px + mv) * 64, m->py * 64);
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->voidd, \
	(m->px) * 64, m->py * 64);
}

void	ft_print_string(t_map *m)
{
	ft_printf("%d\n", m->steps);
	m->test = ft_itoa(m->steps);
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->voidd, \
	0, 0);
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->floor, \
	0, 0);
	mlx_string_put(m->m2->mlx, m->m2->win, 0, 0, 1000, "steps:");
	mlx_string_put(m->m2->mlx, m->m2->win, 7, 14, 1000, m->test);
	free(m->test);
}
