/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:02:22 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:39:57 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_for(char **sp, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

static int	count_word(const char *str, char c)
{
	int	i;
	int	flag;

	if (!str)
		return (0);
	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char	*ft_dup(const char *str, int len, char **spl, int x)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
	{
		ft_free_for(spl, x);
		return (0);
	}
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = -1;
	j = -1;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[++j] = ft_dup(&s[index], (i - index), split, index);
			if (!split[j])
				return (0);
			index = -1;
		}
	}
	split[j + 1] = 0;
	return (split);
}
