/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:07:47 by eandre-f          #+#    #+#             */
/*   Updated: 2022/05/12 14:48:31 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long nbr, char *base)
{
	size_t	index;
	size_t	len_base;
	char	s[21];

	if (base == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	index = 20;
	s[index] = '\0';
	while (nbr != 0 || index == 20)
	{
		index--;
		s[index] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (ft_strdup(&s[index]));
}
