/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:10 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/25 23:10:38 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Calculate string length.
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
  if (!s1)
  {
    s1 = (char *)malloc(sizeof(char) * 1);
    s1[0] = '\0';
  }
	if (!s2 || !s1)
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
  // free(s1);
	return (dst);
}

// Find index of a specific character
int	find_index(char *str, char c)
{
	int	index;

	if (!str)
		return (-1);
  index = 0;
	while (*str)
	{
		if (*str == c)
			return (index);
		index ++;
    str ++;
	}
	return (-1);
}
