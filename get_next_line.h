/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:22:31 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/24 14:44:18 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

char	*get_next_line(int fd);

// Supporting functions
void	clean_buf(char *buf);
int		find_index(char *str, char c);
char	*str_join(char *s1, char *s2);
char	*substr(char *s1, size_t len);
size_t	str_length(char *str);
#endif
