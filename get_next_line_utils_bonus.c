/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:15:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/11/22 17:50:56 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strchr(const char *s, int c)
{
    if (!s)
       return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	a;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof (char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		dest[i] = s2[a];
		i++;
		a++;
	}
	dest [i] = '\0';
	return (dest);
}