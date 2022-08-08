/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subspecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:29:34 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/08 23:33:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_subspec_buffer(t_holder *hdr)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (hdr->width + 1));
	if (!buffer)
		return (NULL);
	if (hdr->flag_zero)
		ft_memset(buffer, '0', hdr->width);
	else
		ft_memset(buffer, ' ', hdr->width);
	buffer[hdr->width] = '\0';
	return (buffer);
}

static void	ft_subspec_move_minus_sign(char **str, size_t	i, t_holder *hdr)
{
	(*str)[i] = '-';
	if (hdr->flag_zero)
		(*str)[hdr->width] = '0';
	else
		(*str)[hdr->width] = ' ';
}

void	ft_subspec_justify(char **str, t_holder *hdr)
{
	char	*newstr;
	char	*buffer;
	size_t	index;

	buffer = ft_subspec_buffer(hdr);
	if (!buffer)
		return ;
	if (hdr->flag_minus)
	{
		newstr = ft_strjoin(*str, buffer);
		ft_strlcpy(buffer, newstr, hdr->width + 1);
	}
	else
	{
		newstr = ft_strjoin(buffer, *str);
		index = ft_strlen(newstr) - hdr->width;
		if (hdr->flag_zero && *str[0] == '-')
			ft_subspec_move_minus_sign(&newstr, index, hdr);
		ft_strlcpy(buffer, &newstr[index], hdr->width + 1);
	}
	free(newstr);
	ft_strupd(str, buffer);
	hdr->length = hdr->width;
}

void	ft_subspec_minimum_number(char **str, size_t size)
{
	char	*newstr;
	size_t	len;
	char	zero;

	zero = '0';
	if (*str[0] == '-')
		size++;
	len = ft_strlen(*str);
	if (len >= size)
		return ;
	size = size - len;
	newstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!newstr)
		return ;
	ft_memset(newstr, zero, size);
	newstr[size] = '\0';
	if (*str[0] == '-')
	{
		newstr[0] = '-';
		*str[0] = zero;
	}
	ft_strupd(str, ft_strjoin(newstr, *str));
	free(newstr);
}
