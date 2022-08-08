/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_pct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:35:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:52:17 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_specifier_pct(t_format *fmt)
{
	char	c;

	c = '%';
	fmt->length += ft_writestr(fmt, 1, &c, 1);
	fmt->i++;
}
