/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:10 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/24 15:41:57 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Clean the buffer
void	clean_buf(char *buf)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i ++;
	}
}

//Calculate string length
size_t	str_length(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		len ++;
		str ++;
	}
	return (len);
}

// Concatenate two strings and return new string.
char	*str_join(char *s1, char *s2)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s2)
		return (0);
	dst = (char *)malloc((str_length(s1) + str_length(s2) + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (s1 && *s1)
	{
		dst[i++] = *s1;
		s1 ++;
	}
	while (s2 && *s2)
	{
		dst[i++] = *s2;
		s2 ++;
	}
	dst[i] = '\0';
	return (dst);
}

// Find index of a specific character
int	find_index(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index ++;
	}
	return (-1);
}

// Create a substring.
char	*substr(char *s1, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
