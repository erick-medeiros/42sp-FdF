/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:26:51 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:42:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (fmt == NULL)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->length = 0;
	fmt->fill_str = 0;
	fmt->str_i = 0;
	fmt->size_str = 0;
	fmt->str = NULL;
	return (fmt);
}

t_holder	*ft_initialize_holder(void)
{
	t_holder	*hdr;

	hdr = (t_holder *)malloc(sizeof(t_holder));
	if (hdr == NULL)
		return (NULL);
	hdr->flag_minus = 0;
	hdr->flag_plus = 0;
	hdr->flag_space = 0;
	hdr->flag_numbersign = 0;
	hdr->flag_zero = 0;
	hdr->subspec_width = 0;
	hdr->width = 0;
	hdr->subspec_precision = 0;
	hdr->precision = 0;
	hdr->length = 0;
	return (hdr);
}
