/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:12 by basile            #+#    #+#             */
/*   Updated: 2023/12/06 16:33:49 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_split_join(char *line, char *buff, char *dest)
{
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			dest[i] = line[i];
	while (buff[j] != '\0')
		dest[i++] = buff[j++];
	dest[ft_strlen(line) + ft_strlen(buff)] = '\0';
	return (dest);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*dest;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!buff)
		return (free(line), NULL);
	dest = malloc(sizeof(char) * ((ft_strlen(buff) + ft_strlen(line)) + 1));
	if (dest == NULL)
		return (free(line), NULL);
	dest = ft_split_join(line, buff, dest);
	free (line);
	return (dest);
}
