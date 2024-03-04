/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdel-m <aabdel-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:52:37 by aabdel-m          #+#    #+#             */
/*   Updated: 2024/02/28 14:40:56 by aabdel-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *storage, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(storage) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (storage)
		while (storage[++i] != '\0')
			str[i] = storage[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(storage) + ft_strlen(buff)] = '\0';
	free(storage);
	return (str);
}

char	*ft_get_line(char *storage)
{
	int		i;
	char	*str;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		str[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		str[i] = storage[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rest(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}
