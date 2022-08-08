/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:59:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/10 22:24:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *) s1;
	s2uc = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1uc[i] != s2uc[i] || s1uc[i] == '\0' || s2uc[i] == '\0')
			return (s1uc[i] - s2uc[i]);
		i++;
	}
	return (0);
}
