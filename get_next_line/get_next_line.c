/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporzig <fporzig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:48:24 by fporzig           #+#    #+#             */
/*   Updated: 2025/01/16 16:24:30 by fporzig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *str)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!str)
			str = gnl_strdup("");
		temp = gnl_strjoin(str, buffer);
		free(str);
		str = temp;
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

static char	*extract_line(char **str)
{
	char	*line;
	char	*temp;
	char	*newline_pos;

	newline_pos = gnl_strchr(*str, '\n');
	if (newline_pos)
	{
		line = gnl_substr(*str, 0, newline_pos - *str + 1);
		temp = gnl_strdup(*str + (newline_pos - *str + 1));
	}
	else
	{
		line = gnl_strdup(*str);
		temp = NULL;
	}
	free(*str);
	*str = temp;
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	str = read_line(fd, buffer, str);
	free(buffer);
	if (!str)
	{
		str = NULL;
		return (NULL);
	}
	return (extract_line(&str));
}
