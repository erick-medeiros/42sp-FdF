/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:16:22 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/12 03:55:26 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;
	size_t	len_l;
	char	*bigc;

	bigc = (char *)big;
	len_l = ft_strlen(little);
	if (len_l == 0)
		return (bigc);
	i = 0;
	while (i < len && bigc[i] != '\0')
	{
		o = 0;
		while (bigc[i + o] == little[o] && (i + o) < len)
		{
			if (little[o + 1] == '\0')
				return (&bigc[i]);
			o++;
		}
		i++;
	}
	return (NULL);
}
