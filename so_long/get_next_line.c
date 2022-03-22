/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:14:19 by sdarci            #+#    #+#             */
/*   Updated: 2021/12/17 18:36:06 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*amatilda(char	*backupp)
{
	backupp = (char *)malloc((sizeof("") + 1));
	if (!backupp)
		exit(1);
	backupp[0] = '\0';
	return (backupp);
}

char	*func(int fd, char *buf, char *backup)
{
	int		reed;
	char	*tmp;

	reed = 1;
	while (reed > 0)
	{
		reed = read(fd, buf, BUFFER_SIZE);
		if (reed == -1)
			return (0);
		else if (reed == 0)
			break ;
		buf[reed] = '\0';
		if (!backup)
			backup = amatilda(backup);
		if (!backup)
			return (NULL);
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*tline;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	tline = func(fd, buf, backup);
	free(buf);
	if (!tline)
		return (NULL);
	backup = extract(tline);
	return (tline);
}
