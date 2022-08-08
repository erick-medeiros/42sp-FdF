/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:18:24 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:51:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_writestr(t_format *fmt, int fd, const void *buf, size_t count)
{
	size_t	length;
	size_t	i;

	if (fmt->fill_str == 1)
	{
		i = 0;
		while (i < count && fmt->str_i < fmt->size_str)
		{
			fmt->str[fmt->str_i] = ((char *)buf)[i];
			++i;
			++fmt->str_i;
		}
		fmt->str[fmt->str_i] = '\0';
		length = i;
	}
	else
		length = write(fd, buf, count);
	return (length);
}
