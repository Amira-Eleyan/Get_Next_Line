/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdel-m <aabdel-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:30:42 by aabdel-m          #+#    #+#             */
/*   Updated: 2024/02/28 14:43:02 by aabdel-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *storage);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *storage, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *storage);
char	*ft_rest(char *storage);

#endif