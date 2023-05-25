/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/25 23:11:16 by dnishsha         ###   ########.fr       */
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

// Read from the file to the buffer
static char	*fd_read(int fd, char *left_str)
{
	int		bytes_rd;
	char	*buf;

	bytes_rd = BUFFER_SIZE;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (bytes_rd == BUFFER_SIZE && find_index(buf, '\n') == -1)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd < 0)
		{
			free (buf);
			return (0);
		}
		buf[bytes_rd] = '\0';
		left_str = str_join(left_str, buf);
	}
	free(buf);
	return (left_str);
}

static char *get_line(char *left_str)
{
  char *line;
  int pos;
  int i;

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
  if (left_str[i] != '\n')
  {
    line[i] = left_str[i];
    i ++;
  }
  line[i] = '\0';
  return (line);
}

static char  *get_residual_str(char *left_str)
{
  char *residual_str;
  int pos;
  int i;

  pos = find_index(left_str, '\n');
  i = 0;
  if (pos != -1)
    residual_str = (char *)malloc(sizeof(char) * (str_length(left_str) - pos));
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
	static char	*left_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
  left_str = fd_read(fd, left_str);
  if (!left_str || str_length(left_str) == 0)
  {
    free(left_str);
    return (0);
  }
  line = get_line(left_str);
  if (!line || str_length(line) == 0)
  {
    free(left_str);
    return (0);
  }
  left_str = get_residual_str(left_str);
	return (line);
}



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
// 		printf("Line %d: -%s-", i + 1, line);
// 		free(line);
// 		i ++;
// 	}
// 	close(fd);
// 	return (0);
// }
