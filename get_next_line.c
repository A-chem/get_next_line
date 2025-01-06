/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:18:58 by achemlal          #+#    #+#             */
/*   Updated: 2024/12/07 10:28:55 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_set_line(char **str)
{
	size_t	pos_nline;
	char	*line;
	char	*temp;

	if (!(*str) || !(*str)[0])
		return (NULL);
	if (ft_strchr(*str, '\n'))
		pos_nline = ft_strchr(*str, '\n') - *str;
	else
		pos_nline = ft_strlen(*str);
	if ((*str)[pos_nline] == '\n')
		pos_nline++;
	line = ft_substr(*str, 0, pos_nline);
	if (!line)
		return (NULL);
	temp = ft_substr(*str, pos_nline, ft_strlen(*str) - pos_nline);
	if (!temp)
		return (free(line), NULL);
	free(*str);
	*str = temp;
	return (line);
}

static char	*ft_readfile(int fd, char **str, char *buffer)
{
	ssize_t	readbuf;
	char	*line;
	char	*temp;

	readbuf = 1;
	while (readbuf > 0)
	{
		readbuf = read(fd, buffer, BUFFER_SIZE);
		if (readbuf == -1)
			return (free(*str), free(buffer), NULL);
		if (readbuf == 0)
			break ;
		buffer[readbuf] = '\0';
		temp = *str;
		*str = ft_strjoin(*str, buffer);
		if (!*str)
			return (free(temp), NULL);
		free(temp);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	line = ft_set_line(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*str;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || read(fd, NULL, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_readfile(fd, &str, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (line);
}
