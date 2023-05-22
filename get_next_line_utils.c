/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:10 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/22 22:33:07 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// Clean the buffer
void  ft_clean_buf(char *buf)
{
  int i;

  i = 0;
  while (i <= BUFFER_SIZE)
  {
    buf[i] = '\0';
    i ++;
  }
}
