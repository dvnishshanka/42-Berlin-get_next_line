/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/26 15:06:55 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fd: The file descriptor to read from
Write a function that returns a line read from a
file descriptor

Return: Read line: correct behavior
		NULL: there is nothing else to read, or an error occurred
*/

#include "get_next_line_bonus.h"

// Read from the file to the buffer and join them to a string until a
// new line or end of file occur in the buffer.
static char	*fd_read(int fd, char *left_str)
{
	int		bytes_rd;
	char	*buf;

	bytes_rd = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (bytes_rd != 0 && find_index(left_str, '\n') == -1)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(left_str);
			free (buf);
			buf = NULL;
			return (0);
		}
		buf[bytes_rd] = '\0';
		left_str = str_join(left_str, buf);
	}
	free(buf);
	buf = NULL;
	return (left_str);
}

static char	*get_line(char *left_str)
{
	char	*line;
	int		pos;
	int		i;

	pos = find_index(left_str, '\n');
	i = 0;
	if (pos != -1)
		line = (char *)malloc(sizeof(char) * (pos + 2));
	else
		line = (char *)malloc(sizeof(char) * (str_length(left_str) + 1));
	if (!line)
		return (0);
	while (left_str[i] && left_str[i] != '\n')
	{
		line[i] = left_str[i];
		i ++;
	}
	if (left_str[i] == '\n')
	{
		line[i] = left_str[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_residual_str(char *left_str)
{
	char	*residual_str;
	int		pos;
	int		i;

	pos = find_index(left_str, '\n');
	i = 0;
	if (pos != -1)
		residual_str = (char *)malloc(sizeof(char)
				*(str_length(left_str) - pos));
	else
		residual_str = (char *)malloc(sizeof(char) * 1);
	if (!residual_str)
		return (0);
	while (pos != -1 && left_str[pos + 1 + i])
	{
		residual_str[i] = left_str[pos + 1 + i];
		i ++;
	}
	residual_str[i] = '\0';
	free(left_str);
	return (residual_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str[1000] = {NULL};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = fd_read(fd, left_str[fd]);
	if (!left_str[fd])
		return (0);
	line = get_line(left_str[fd]);
	if (!line || str_length(line) == 0)
	{
		free(left_str[fd]);
		free(line);
		left_str[fd] = NULL;
		return (NULL);
	}
	left_str[fd] = get_residual_str(left_str[fd]);
	return (line);
}

// Main file for testing
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line[2];
	int		i;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	line[0] = get_next_line(fd1);
	printf("Line : %s", line[0]);
	free(line[0]);
	line[1] = get_next_line(fd2);
	printf("Line : %s", line[1]);
	free(line[1]);
	line[0] = get_next_line(fd1);
	printf("Line : %s", line[0]);
	free(line[0]);
	line[1] = get_next_line(fd2);
	printf("Line : %s", line[1]);
	free(line[1]);
	line[0] = get_next_line(fd1);
	printf("Line : %s", line[0]);
	free(line[0]);
	line[1] = get_next_line(fd2);
	printf("Line : %s", line[1]);
	free(line[1]);
	close(fd1);
	close(fd2);
	return (0);
}*/
