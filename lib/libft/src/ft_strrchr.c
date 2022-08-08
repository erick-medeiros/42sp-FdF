/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:49:25 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/07 03:51:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	caract;
	char	*sc;

	caract = (unsigned char) c;
	sc = (char *) s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (sc[i] == caract)
			return (&sc[i]);
		i--;
	}
	if (c == '\0')
		return (&sc[i]);
	return (NULL);
}
