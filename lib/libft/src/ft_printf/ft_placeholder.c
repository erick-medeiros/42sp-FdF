/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:29:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/08 23:33:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_placeholder(t_format *fmt)
{
	t_holder	*hdr;

	hdr = ft_initialize_holder();
	fmt->i++;
	ft_placeholder_subspec(fmt, hdr);
	if (fmt->format[fmt->i] == 'c')
		ft_specifier_c(fmt, hdr);
	else if (fmt->format[fmt->i] == 's')
		ft_specifier_s(fmt, hdr);
	else if (fmt->format[fmt->i] == 'p')
		ft_specifier_p(fmt, hdr);
	else if (fmt->format[fmt->i] == 'd' || fmt->format[fmt->i] == 'i')
		ft_specifier_d_i(fmt, hdr);
	else if (fmt->format[fmt->i] == 'u')
		ft_specifier_ui(fmt, hdr, "", "0123456789");
	else if (fmt->format[fmt->i] == 'o')
		ft_specifier_ui(fmt, hdr, "0", "01234567");
	else if (fmt->format[fmt->i] == 'x')
		ft_specifier_ui(fmt, hdr, "0x", "0123456789abcdef");
	else if (fmt->format[fmt->i] == 'X')
		ft_specifier_ui(fmt, hdr, "0X", "0123456789ABCDEF");
	else if (fmt->format[fmt->i] == '%')
		ft_specifier_pct(fmt);
	free(hdr);
}

void	ft_placeholder_subspec(t_format *fmt, t_holder *hdr)
{
	while (ft_strchr(" +#-", fmt->format[fmt->i]))
	{
		if (fmt->format[fmt->i] == ' ')
			hdr->flag_space = 1;
		else if (fmt->format[fmt->i] == '+')
			hdr->flag_plus = 1;
		else if (fmt->format[fmt->i] == '#')
			hdr->flag_numbersign = 1;
		else if (fmt->format[fmt->i] == '-')
			hdr->flag_minus = 1;
		fmt->i++;
	}
	ft_placeholder_subspec_width(fmt, hdr);
	if (fmt->format[fmt->i] == '.')
	{
		hdr->subspec_precision = 1;
		hdr->flag_zero = 0;
		fmt->i++;
		ft_placeholder_subspec_precision(fmt, hdr);
	}
}

void	ft_placeholder_subspec_width(t_format *fmt, t_holder *hdr)
{
	if (fmt->format[fmt->i] == '*')
	{
		hdr->width = (int)va_arg(fmt->ap, int);
		fmt->i++;
	}
	else if (fmt->format[fmt->i] == '0' && fmt->format[fmt->i + 1] == '*')
	{
		hdr->flag_zero = 1;
		hdr->width = (int)va_arg(fmt->ap, int);
		fmt->i += 2;
	}
	else if (ft_isdigit(fmt->format[fmt->i]))
	{
		hdr->width = ft_atoi(&(fmt->format[fmt->i]));
		if (hdr->width > 0 && fmt->format[fmt->i] == '0')
			hdr->flag_zero = 1;
		while (ft_isdigit(fmt->format[fmt->i]))
			fmt->i++;
	}
	if (hdr->width > 0)
		hdr->subspec_width = 1;
	else
		hdr->flag_zero = 0;
}

void	ft_placeholder_subspec_precision(t_format *fmt, t_holder *hdr)
{
	if (ft_isdigit(fmt->format[fmt->i]))
	{
		hdr->precision = ft_atoi(&(fmt->format[fmt->i]));
		while (ft_isdigit(fmt->format[fmt->i]))
			fmt->i++;
	}
	else if (fmt->format[fmt->i] == '*')
	{
		hdr->precision = (int)va_arg(fmt->ap, int);
		fmt->i++;
	}
}
