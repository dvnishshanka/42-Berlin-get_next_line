/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/24 09:02:27 by dnishsha         ###   ########.fr       */
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

char  *fd_read(int fd, char *remain_str)
{
	int		bytes_rd;
  char  *buf;
  int   pos;
  char  *line;

	bytes_rd = 1;
  pos = -1;
  buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  line = remain_str;
  if (!buf || !line)
    return (0);
  while (bytes_rd > 0 && pos == -1)
	{
		clean_buf(buf);
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		// printf("\nbuf(%d): %s\n", BUFFER_SIZE, buf);
		if (bytes_rd < 0)
		{
			free (buf);
      free(line);
			return (0);
		}
		else if (bytes_rd > 0)
		{
			pos = find_index(buf, '\n');
      // printf("\npos: %d\n", pos);
			if (pos > 0)
			{
				line = str_join(line, substr(buf, pos + 1));
        remain_str = str_join(&buf[pos + 1], "");
        	printf("\nline pos >0: %s, pos: %d\n", line, pos);
          printf ("\nRemain str: %s", remain_str);
				break ;
			}
			else if (pos == -1)
      {
				line = str_join(line, buf);
        	// printf("\nline: %s, pos: %d\n", line, pos);
      }
		}
	}
  free(buf);
  return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain_str;
  char  *line;
  int   pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
  remain_str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  if (!remain_str)
    return (0);
  pos = find_index(remain_str, '\n');
  while (pos != -1)
  {
    line = substr(remain_str, pos + 1);
    remain_str = substr(&remain_str[pos +1], BUFFER_SIZE - pos);
    return (line);
  }
  line = fd_read(fd, remain_str);
  printf ("\nRemain str: %s", remain_str);
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
		// printf("Line %d: %s", i + 1, line);
		i ++;
	}
	close(fd);
	return (0);
}
