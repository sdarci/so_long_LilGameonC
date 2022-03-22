/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:49:37 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/18 16:36:49 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map4(t_map *p)
{
	int	j;

	j = 0;
	if (!p->col || !p->player || !p->exit || p->player > 1)
		return (-1);
	while (p->mapspl[p->width - 1][j])
	{
		if (p->mapspl[p->width - 1][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	valid_map3(t_map *p)
{
	int	i;
	int	j;

	i = 1;
	while (p->mapspl[i])
	{
		j = 0;
		while (p->mapspl[i][j] != '\0')
		{
			if (p->mapspl[i][j] != 'E' && p->mapspl[i][j] != '0'\
			&& p->mapspl[i][j] != '1' && p->mapspl[i][j] != 'P' \
			&& p->mapspl[i][j] != 'C')
				return (-1);
			j++;
		}
		if (p->mapspl[i][p->valid_len - 1] != '1')
			return (-1);
		if (p->mapspl[i][0] != '1')
			return (-1);
		i++;
	}
	p->width = i;
	return (0);
}

int	valid_map2(t_map *p)
{
	int	j;
	int	i;

	i = 0;
	while (p->mapspl[i])
	{
		j = 0;
		while (p->mapspl[i][j] != '\0')
		{
			if (p->mapspl[i][j] == 'P')
			{
				p->player++;
				p->px = j;
				p->py = i;
			}
			if (p->mapspl[i][j] == 'C')
				p->col++;
			if (p->mapspl[i][j] == 'E')
				p->exit++;
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing_map(int fd, t_map *params)
{
	int		i;
	char	*line;
	char	*lines;

	i = 0;
	lines = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = ft_strnjoin(lines, line, ft_strlen(line));
		line = ft_free(line);
	}
	close(fd);
	params->map = lines;
	params->mapspl = ft_split(params->map, '\n');
	params->valid_len = ft_strlen(params->mapspl[0]);
	free(lines);
}

int	valid_map(t_map *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (p->mapspl[i][j] != '\0')
	{
		if (p->mapspl[i][j] != '1')
			return (-1);
		j++;
	}
	while (p->mapspl[i])
	{
		if (ft_strlen(p->mapspl[i]) != p->valid_len)
			return (-1);
		i++;
	}
	if (valid_map2(p) == -1)
		return (-1);
	if (valid_map3(p) == -1)
		return (-1);
	if (valid_map4(p) == -1)
		return (-1);
	return (0);
}
