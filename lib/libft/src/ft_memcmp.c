/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:20:58 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/06 00:23:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *)s1;
	s2uc = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1uc[i] != s2uc[i])
			return (s1uc[i] - s2uc[i]);
		i++;
	}
	return (0);
}
