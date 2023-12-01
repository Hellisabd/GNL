/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:43:24 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/01 16:18:01 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
# endif

char	    *get_next_line(int fd);
char	    *ft_strchr(const char *s, int c);
char	    *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
