/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:33:05 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:52:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_specifier_ui(t_format *fmt, t_holder *hdr, char *prefix, char *base)
{
	unsigned int	ui;
	char			*s;

	ui = (unsigned int)va_arg(fmt->ap, unsigned int);
	s = ft_uitoa_base(ui, base);
	if (hdr->flag_minus)
		hdr->flag_zero = 0;
	if (hdr->subspec_precision)
	{
		if (hdr->precision == 0 && ui == 0)
			ft_strupd(&s, ft_strdup(""));
		else
			ft_subspec_minimum_number(&s, hdr->precision);
	}
	if (hdr->flag_numbersign && ui > 0)
		ft_strupd(&s, ft_strjoin(prefix, s));
	hdr->length = ft_strlen(s);
	if (hdr->subspec_width && hdr->width > hdr->length)
		ft_subspec_justify(&s, hdr);
	fmt->length += ft_writestr(fmt, 1, s, hdr->length);
	fmt->i++;
	free(s);
}
