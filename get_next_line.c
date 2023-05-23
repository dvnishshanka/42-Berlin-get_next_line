/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/23 14:35:12 by dnishsha         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*buf;
	int		bytes_rd;
	char	*line;
	int		pos;

	bytes_rd = 1;
	pos = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (bytes_rd > 0 && pos == -1)
	{
		clean_buf(buf);
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		printf("\nbuf(%d): %s\n", BUFFER_SIZE, buf);
		if (bytes_rd < 0 && pos == -1)
		{
			free (buf);
			return (0);
		}
		else if (bytes_rd > 0)
		{
			pos = find_index(buf, '\n');
			if (pos > 0)
			{
				line = substr(buf, pos + 1);
				break ;
			}
			else if (pos == -1)
				line = str_join(line, buf);
		}
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("Line %d: %s", i, line);
		i ++;
	}
	close(fd);
	return (0);
}
