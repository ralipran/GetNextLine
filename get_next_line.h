/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:46 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/24 19:23:10 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*find_new_line(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*read_and_update(int fd, char *residual);
char	*get_next_line(int fd);
char    *ft_strlcpy_II(char *dst, const char *src, size_t dstsize);

#endif
