/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:23:47 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:52:21 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_specifier_s(t_format *fmt, t_holder *hdr)
{
	char		*s;
	char		*sn;

	sn = (char *)va_arg(fmt->ap, char *);
	hdr->flag_zero = 0;
	if (sn == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(sn);
	if (hdr->subspec_precision)
	{
		if (sn || hdr->precision >= 6)
			ft_strupd(&s, ft_substr(s, 0, hdr->precision));
		else
			ft_strupd(&s, ft_strdup(""));
	}
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
		ft_subspec_justify(&s, hdr);
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}
