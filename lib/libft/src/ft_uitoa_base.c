/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:23:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/05/12 15:24:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	size_t	index;
	size_t	len_base;
	char	s[11];

	if (base == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	index = 10;
	s[index] = '\0';
	while (nbr != 0 || index == 10)
	{
		index--;
		s[index] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (ft_strdup(&s[index]));
}
