/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:28:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/12 02:36:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*s;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s = (char *) malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < ls1)
		s[i] = s1[i];
	i = -1;
	while (++i < ls2)
		s[i + ls1] = s2[i];
	s[i + ls1] = '\0';
	return (s);
}
