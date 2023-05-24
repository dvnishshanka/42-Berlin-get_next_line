/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/24 16:13:02 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fd: The file descriptor to read from
Write a function that returns a line read from a
file descriptor

Return: Read line: correct behavior
		NULL: there is nothing else to read, or an error occurred
*/

#include "get_next_line.h"

#include <stdio.h>

static char	*fd_read(int fd, char *left_str)
{
	int		bytes_rd;
	char	*buf;

	bytes_rd = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (bytes_rd > 0 && find_index(buf, '\n') == -1)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd < 0)
		{
			free (buf);
			free(left_str);
			return (0);
		}
		buf[bytes_rd] = '\0';
		left_str = str_join(left_str, buf);
	}
	free(buf);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pos = find_index(left_str, '\n');
	line = 0;
	if (pos != -1)
	{
		line = substr(left_str, pos + 1);
		left_str = substr(&left_str[pos +1], str_length(left_str) - pos);
		return (line);
	}
	left_str = fd_read(fd, left_str);
	if (str_length(left_str) == 0)
	{
		free(left_str);
		free(line);
		return (0);
	}
	pos = find_index(left_str, '\n');
	if (pos != -1)
	{
		line = substr(left_str, pos + 1);
		left_str = substr(&left_str[pos +1], str_length(left_str) - pos);
	}
	return (line);
}


// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 4)
// 	{
// 		line = get_next_line(fd);
// 		printf("Line %d: %s", i + 1, line);
// 		free(line);
// 		i ++;
// 	}
// 	close(fd);
// 	return (0);
// }
