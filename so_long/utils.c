/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:13:35 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/15 14:13:36 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*buffer;
	size_t	buffer_len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	buffer_len = ft_strlen(s2);
	if (n < buffer_len)
		buffer_len = n;
	buffer = (char *) malloc (ft_strlen(s1) + buffer_len + 1);
	if (buffer == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	buffer_len = i;
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		buffer[i + buffer_len] = s2[i];
		i ++;
	}
	buffer[i + buffer_len] = '\0';
	free((void *)s1);
	return (buffer);
}

void	ft_col_put(t_map *p, t_render_v **w, int i, int j)
{
	mlx_put_image_to_window((*w)->mlx, (*w)->win, p->voidd, \
	j * p->i_h, i * p->i_w);
	mlx_put_image_to_window((*w)->mlx, (*w)->win, p->items, \
	j * p->i_h, i * p->i_w);
}
