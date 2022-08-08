/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grp_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:13:37 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/11 22:43:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

void	ft_toupper_str(char **str)
{
	size_t	i;

	if (str == NULL || *str == NULL)
		return ;
	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = ft_toupper((*str)[i]);
		i++;
	}
}

void	ft_tolower_str(char **str)
{
	size_t	i;

	if (str == NULL || *str == NULL)
		return ;
	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = ft_tolower((*str)[i]);
		i++;
	}
}
