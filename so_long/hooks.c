/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:40:21 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:42:26 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape_won(t_map *p)
{
	int	i;

	i = 0;
	mlx_destroy_image(p->m2->mlx, p->exitt);
	mlx_destroy_image(p->m2->mlx, p->floor);
	mlx_destroy_image(p->m2->mlx, p->pl);
	mlx_destroy_image(p->m2->mlx, p->voidd);
	mlx_destroy_image(p->m2->mlx, p->items);
	mlx_destroy_image(p->m2->mlx, p->exitwon);
	mlx_destroy_image(p->m2->mlx, p->pll);
	mlx_destroy_image(p->m2->mlx, p->m2->win);
	write (1, "U WON\n", 6);
	if (p->mapspl[i])
	{
		while ((p->mapspl)[i])
		{
			free((p->mapspl)[i]);
			i++;
		}
		free(p->mapspl);
	}
	free(p->m2);
	free(p);
	exit(0);
	return (0);
}

int	ft_escape(t_map *p)
{
	int	i;

	i = 0;
	mlx_destroy_image(p->m2->mlx, p->exitt);
	mlx_destroy_image(p->m2->mlx, p->floor);
	mlx_destroy_image(p->m2->mlx, p->pl);
	mlx_destroy_image(p->m2->mlx, p->voidd);
	mlx_destroy_image(p->m2->mlx, p->items);
	mlx_destroy_image(p->m2->mlx, p->exitwon);
	mlx_destroy_image(p->m2->mlx, p->pll);
	mlx_destroy_image(p->m2->mlx, p->m2->win);
	if (p->mapspl[i])
	{
		while ((p->mapspl)[i])
		{
			free((p->mapspl)[i]);
			i++;
		}
		free(p->mapspl);
	}
	free(p->m2);
	free(p);
	exit(0);
}

int	ft_moving_up_down(t_map *m, int mv)
{
	if (m->mapspl[m->py + mv][m->px] == '1')
		return (0);
	if (m->mapspl[m->py + mv][m->px] == 'C')
	{
		m->col -= 1;
		m->mapspl[m->py + mv][m->px] = '0';
	}
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->voidd, \
	(m->px) * 64, m->py * 64);
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->pl, \
	(m->px) * 64, (m->py + mv) * 64);
	if (m->mapspl[m->py + mv][m->px] == 'E' && m->col == 0)
		ft_escape_won (m);
	if (m->mapspl[m->py][m->px] == 'E' && m->col != 0)
		mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->exitt, \
		(m->px) * 64, m->py * 64);
	if (m->col == 0)
		ft_put_win(m);
	m->py += mv;
	m->steps++;
	ft_print_string(m);
	return (1);
}

int	ft_moving_left_right(t_map *m, int mv)
{
	if (m->mapspl[m->py][m->px + mv] == '1')
		return (0);
	if (m->mapspl[m->py][m->px + mv] == 'C')
	{
		m->col -= 1;
		m->mapspl[m->py][m->px + mv] = '0';
	}
	if (mv > 0)
		mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->pl, \
	(m->px + mv) * 64, m->py * 64);
	mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->voidd, \
	(m->px) * 64, m->py * 64);
	if (mv < 0)
		ft_sprite(m, mv);
	if (m->mapspl[m->py][m->px + mv] == 'E' && m->col == 0)
		ft_escape_won(m);
	if (m->mapspl[m->py][m->px] == 'E' && m->col != 0)
		mlx_put_image_to_window(m->m2->mlx, m->m2->win, m->exitt, \
		(m->px) * 64, m->py * 64);
	if (m->col == 0)
		ft_put_win(m);
	m->px += mv;
	m->steps++;
	ft_print_string(m);
	return (1);
}

int	press(int keycode, t_map *m)
{
	if (keycode == 1)
		return (ft_moving_up_down(m, 1));
	if (keycode == 13)
		return (ft_moving_up_down(m, -1));
	if (keycode == 2)
		return (ft_moving_left_right(m, 1));
	if (keycode == 0)
		return (ft_moving_left_right(m, -1));
	if (keycode == ESC)
		ft_escape(m);
	return (0);
}
