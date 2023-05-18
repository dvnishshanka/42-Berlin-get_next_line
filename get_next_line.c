/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:16 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/18 16:54:16 by dnishsha         ###   ########.fr       */
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
  char * buf;

  buf = (char *)malloc(BUFFER_SIZE);
	if (fd < 0)
		return (0);
  read(fd, buf, BUFFER_SIZE);
  printf("%s\n", buf);
	return (0);
}

#include <stdio.h>
 #include <fcntl.h>
int	main(void)
{
  get_next_line(open("test.txt", O_RDONLY));

	return (0);
}
