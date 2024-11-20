/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:31 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/19 18:31:47 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*find_new_line(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*str;

	i = 0;
	s_len = ft_strlen(s);
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (s_len + 1));
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
