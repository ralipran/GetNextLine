/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:38 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/19 17:34:20 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_update(int fd, char *residual)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	size_read;

	while (find_new_line(residual) == NULL)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
		{
			free(residual);
			return (NULL);
		}
		else if (size_read == 0)
			return (residual);
		buffer[size_read] = '\0';
		residual = ft_strjoin(residual, buffer);
		if (residual == NULL)
		{
			free(residual);
			return (NULL);
		}
	}
	return (residual);
}

char	*get_next_line(int fd)
{
	static char	*residual;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	residual = read_and_update(fd, residual);
	if (residual == NULL)
		return (NULL);
	line = ft_substr(residual, 0, find_new_line(residual) - residual + 1);
	if (line == NULL)
		return (NULL);
	residual = ft_strdup(find_new_line(residual) + 1);
	if (residual == NULL)
	{
		free(residual);
		return (NULL);
	}
	return (line);
}
