/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:25:50 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/07 03:58:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	caract;
	char	*sc;

	caract = (unsigned char) c;
	sc = (char *)s;
	i = 0;
	while (sc[i] != '\0')
	{
		if (sc[i] == caract)
			return (&sc[i]);
		i++;
	}
	if (caract == '\0')
		return (&sc[i]);
	return (NULL);
}
