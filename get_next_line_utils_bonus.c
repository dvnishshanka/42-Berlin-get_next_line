/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:10 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/26 14:33:39 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Calculate string length.
size_t	str_length(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len ++;
	}
	return (len);
}

// Concatenate two strings and return new string.
char	*str_join(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
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
	while (s1 && s1[j])
		dst[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (free(s1), dst);
}

// Find index of the first occurrence of a specific character
int	find_index(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}
