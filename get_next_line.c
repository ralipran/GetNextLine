/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:38 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/24 19:22:44 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_and_update(int fd, char *residual)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	size_read;

	while (find_new_line(residual) == NULL)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		//printf("test\n");
		if (size_read < 0)
		{
			//free(residual);
			//printf("test\n");
			return (NULL);
		}
		else if (size_read == 0)
		{
			//printf("c lui\n");
			return (residual);
		}
		buffer[size_read] = '\0';
		if (residual == NULL)
		{
			residual = ft_strlcpy_II(residual, buffer, size_read);
		}
		printf("buffer: %s\n", buffer);
		residual = ft_strjoin(residual, buffer);
		if (residual == NULL)
		{
			free(residual);
			printf("c lui\n");
			return (NULL);
		}
	}
	return (residual);
}

char	*get_next_line(int fd)
{
	static char	*residual;
	char		*line;
	char		*nl_position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fd valide\n");
	residual = read_and_update(fd, residual);
	if (residual == NULL)
		return (NULL);
	printf("fd valide\n");
	nl_position = find_new_line(residual);
	if (nl_position == NULL)
	{
		line = ft_strdup(residual);
		free(residual);
		residual = NULL;
		return (line);
	}
	line = ft_substr(residual, 0, nl_position - residual + 1);
	residual = ft_strdup(nl_position + 1);
	return (line);
}
