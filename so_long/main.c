/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:49:01 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/18 16:36:17 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_bers(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '.')
	{
		i++;
	}
	if (argv[i] != '.')
		return (1);
	if (argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i + 3] \
	== 'r' && argv[i + 4] == '\0')
		return (0);
	return (1);
}

void	ft_null_pa(t_map *params)
{
	params->correct = 0;
	params->map = NULL;
	params->valid_len = 0;
	params->width = 1;
	params->col = 0;
	params->player = 0;
	params->exit = 0;
	params->steps = 0;
	params->i_h = 64;
	params->i_w = 64;
	params->mapspl = NULL;
	params->test = NULL;
}

int	main(int argc, char **argv)
{
	int		fd;
	char	b[1];
	t_map	*params;

	if (argc != 2)
		return (-1 * write(2, "ERR: wrong number of arguments\n", 31));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1 * write(2, "ERR: can't open file for read\n", 30));
	if (read(fd, b, 0) < 0)
		return (-1 * write(2, "ERR: can't read from file\n", 26));
	params = malloc(sizeof(t_map));
	if (!params)
		exit (-1 * write(2, "ERR: malloc error\n", 18));
	if (ft_check_bers(argv[1]) != 0)
		exit (-1 * write(2, "ERR: map not .ber\n", 18));
	ft_null_pa(params);
	parsing_map(fd, params);
	if (valid_map(params) == -1)
	{
		write(2, "ERR MAP\n", 8);
		exit(1);
	}
	prepare(params);
}
