/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:25:17 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:48:11 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_hook(t_map *p)
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

void	loop_f_map(t_map *p, t_render_v **w, int i, int j)
{
	while (p->mapspl[i])
	{
		j = 0;
		while (p->mapspl[i][j])
		{
			if (p->mapspl[i][j] == '1')
				mlx_put_image_to_window((*w)->mlx, (*w)->win, p->floor, \
				j * p->i_h, i * p->i_w);
			if (p->mapspl[i][j] == 'P')
				mlx_put_image_to_window((*w)->mlx, (*w)->win, p->pl, \
				j * p->i_h, i * p->i_w);
			if (p->mapspl[i][j] == '0')
				mlx_put_image_to_window((*w)->mlx, (*w)->win, p->voidd, \
				j * p->i_h, i * p->i_w);
			if (p->mapspl[i][j] == 'E')
				mlx_put_image_to_window((*w)->mlx, (*w)->win, p->exitt, \
				j * p->i_h, i * p->i_w);
			if (p->mapspl[i][j] == 'C')
				ft_col_put(p, w, i, j);
			j++;
		}
		i++;
	}
}

void	open_images(t_map *m, t_render_v **ma)
{
	m->exitt = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/exit.xpm", \
	&(m->i_h), &(m->i_w));
	m->floor = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/wall.xpm", \
	&(m->i_h), &(m->i_w));
	m->voidd = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/void.xpm", \
	&(m->i_h), &(m->i_w));
	m->pl = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/player.xpm", \
	&(m->i_h), &(m->i_w));
	m->items = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/collect.xpm", \
	&(m->i_h), &(m->i_w));
	m->pll = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/playerleft.xpm", \
	&(m->i_h), &(m->i_w));
	m->exitwon = mlx_xpm_file_to_image((*ma)->mlx, "./xpms/exitclose.xpm", \
	&(m->i_h), &(m->i_w));
}

void	ft_close(void)
{
	write (1, "ERR\n", 4);
	exit (0);
}

void	prepare(t_map *params)
{
	params->m2 = malloc(sizeof(t_render_v));
	if (!(params->m2))
	{
		ft_free(params);
		exit(1);
	}
	params->m2->mlx = mlx_init();
	params->m2->win = mlx_new_window(params->m2->mlx, params->valid_len * 64, \
	params->width * 64, "so_long sdarci");
	open_images(params, &(params->m2));
	mlx_put_image_to_window(params->m2->mlx, params->m2->win, params->voidd, \
				params->px * 64, params->py * 64);
	loop_f_map(params, &(params->m2), 0, 0);
	mlx_hook(params->m2->win, 2, 0, press, params);
	mlx_hook(params->m2->win, 17, 0, exit_hook, params);
	mlx_loop(params->m2->mlx);
}
