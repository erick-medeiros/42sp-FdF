/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_octantes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:42:42 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 12:37:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	octante_1_5(t_bresenham *b)
{
	b->error = (2 * b->delta_y) - b->delta_x;
	while (b->xi <= b->p2.x)
	{
		bresenham_draw(b);
		if (b->error <= 0)
			b->error += b->delta_y;
		else
		{
			b->error += (b->delta_y - b->delta_x);
			++b->yi;
		}
		++b->xi;
	}
}

static void	octante_8_4(t_bresenham *b)
{
	b->error = (2 * b->delta_y) + b->delta_x;
	while (b->xi <= b->p2.x)
	{
		bresenham_draw(b);
		if (b->error >= 0)
			b->error += b->delta_y;
		else
		{
			b->error += (b->delta_y + b->delta_x);
			--b->yi;
		}
		++b->xi;
	}
}

static void	octante_2_6(t_bresenham *b)
{
	b->error = (2 * b->delta_x) - b->delta_y;
	while (b->yi <= b->p2.y)
	{
		bresenham_draw(b);
		if (b->error <= 0)
			b->error += b->delta_x;
		else
		{
			b->error += (b->delta_x - b->delta_y);
			++b->xi;
		}
		++b->yi;
	}
}

static void	octante_7_3(t_bresenham *b)
{
	b->error = (2 * b->delta_x) + b->delta_y;
	while (b->yi >= b->p2.y)
	{
		bresenham_draw(b);
		if (b->error <= 0)
			b->error += b->delta_x;
		else
		{
			b->error += (b->delta_x + b->delta_y);
			++b->xi;
		}
		--b->yi;
	}
}

void	bresenham_octantes(t_bresenham *b)
{
	if ((abs(b->delta_x) > abs(b->delta_y)) && (b->delta_y > 0))
		octante_1_5(b);
	else if ((abs(b->delta_x) > abs(b->delta_y)) && (b->delta_y < 0))
		octante_8_4(b);
	else if ((abs(b->delta_x) < abs(b->delta_y)) && (b->delta_y > 0))
		octante_2_6(b);
	else if ((abs(b->delta_x) < abs(b->delta_y)) && (b->delta_y < 0))
		octante_7_3(b);
}
