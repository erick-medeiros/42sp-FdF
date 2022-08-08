/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:46:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/13 06:55:37 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	int		nsave;
	char	s[12];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	nsave = n;
	if (n < 0)
		n = n * -1;
	s[11] = '\0';
	i = 11;
	while (n != 0)
	{
		i--;
		s[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (nsave < 0)
	{
		i--;
		s[i] = '-';
	}
	return (ft_strdup(&s[i]));
}
