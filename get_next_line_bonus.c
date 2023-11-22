/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:00:13 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/11/22 17:11:32 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (*src != '\n' && src[i] != '\0')
		src++;
	if (!*src)
	{
		free(src);
		return (NULL);
	}
	if (*src == '\n')
		src++;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_actual(char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!src[i])
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_transfer_buff(int fd, char *line)
{
	int		read_bytes;
	char		*buffer;

	read_bytes = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*res[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res[fd] = ft_transfer_buff(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	line = ft_actual(res[fd]);
	res[fd] = ft_next(res[fd]);
	return (line);
}
