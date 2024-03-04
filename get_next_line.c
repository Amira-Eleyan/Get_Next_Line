/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdel-m <aabdel-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:52:55 by aabdel-m          #+#    #+#             */
/*   Updated: 2024/02/28 16:08:09 by aabdel-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_read(int fd, char *storage)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(storage, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(0, 0, 0) < 0)
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (0);
	}
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = ft_rest(storage);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int fdd;

// 	fd = open("example.txt", O_RDONLY);
// 	fdd = open("example.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s\n", get_next_line(fdd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }