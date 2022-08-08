/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:18:36 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:51:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_specifier_c(t_format *fmt, t_holder *hdr)
{
	char	c;
	char	*s;

	c = (char)va_arg(fmt->ap, int);
	if (hdr->subspec_width && hdr->width > 1)
	{
		s = ft_strdup("");
		ft_subspec_justify(&s, hdr);
		if (hdr->flag_minus)
			s[0] = c;
		else
			s[hdr->width - 1] = c;
		fmt->length += ft_writestr(fmt, 1, s, hdr->width);
		free(s);
	}
	else
		fmt->length += ft_writestr(fmt, 1, &c, 1);
	fmt->i++;
}
