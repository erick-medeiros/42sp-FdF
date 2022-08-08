/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:45:03 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/11 22:09:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_validate_base(char *base)
{
	size_t	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (!ft_isprint(base[i]))
			return (0);
		if (ft_strchr(&base[i + 1], base[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		val;
	int		base_len;

	i = 0;
	val = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, str[i]))
	{
		c = 0;
		while (base[c] != str[i] && base[c])
			c++;
		val = (val * base_len) + c;
		i++;
	}
	return (val);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		val;
	size_t	i;

	if (!ft_validate_base(base))
		return (0);
	sign = 1;
	val = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x' || str[i] == 'X')
			i++;
	}
	val = convert_from_base(&str[i], base);
	return (val * sign);
}
