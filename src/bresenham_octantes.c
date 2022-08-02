/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_octantes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:42:42 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 00:34:14 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham_axis(t_bresenham *b)
{
	while (b->delta_x > b->xi - b->p1.x || b->delta_y > b->yi - b->p1.y)
	{
		bresenham_draw(b);
		if (b->delta_x > 0)
			b->xi++;
		else if (b->delta_x < 0)
			b->xi--;
		if (b->delta_y > 0)
			b->yi++;
		else if (b->delta_y < 0)
			b->yi--;
	}
}

void	bresenham_octante_1_5(t_bresenham *b)
{
	b->decision = 2 * b->delta_y - b->delta_x;
	while (++b->xi < b->p2.x)
	{
		if (b->decision <= 0)
			b->decision += b->delta_y;
		else
		{
			b->decision += (b->delta_y - b->delta_x);
			++b->yi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_8_4(t_bresenham *b)
{
	b->decision = 2 * b->delta_y + b->delta_x;
	while (++b->xi < b->p2.x)
	{
		if (b->decision >= 0)
			b->decision += b->delta_y;
		else
		{
			b->decision += (b->delta_y + b->delta_x);
			--b->yi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_2_6(t_bresenham *b)
{
	b->decision = 2 * b->delta_x - b->delta_y;
	while (++b->yi < b->p2.y)
	{
		if (b->decision <= 0)
			b->decision += b->delta_x;
		else
		{
			b->decision += (b->delta_x - b->delta_y);
			++b->xi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_7_3(t_bresenham *b)
{
	b->decision = 2 * b->delta_x + b->delta_y;
	while (--b->yi > b->p2.y)
	{
		if (b->decision <= 0)
			b->decision += b->delta_x;
		else
		{
			b->decision += (b->delta_x + b->delta_y);
			++b->xi;
		}
		bresenham_draw(b);
	}
}
