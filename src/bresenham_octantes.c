/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_octantes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:42:42 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/28 03:41:26 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham_axis(t_bresenham *b)
{
	while (b->_delta_x > b->_xi - b->p1.x || b->_delta_y > b->_yi - b->p1.y)
	{
		bresenham_draw(b);
		if (b->_delta_x > 0)
			b->_xi++;
		else if (b->_delta_x < 0)
			b->_xi--;
		if (b->_delta_y > 0)
			b->_yi++;
		else if (b->_delta_y < 0)
			b->_yi--;
	}
}

void	bresenham_octante_1_5(t_bresenham *b)
{
	b->_decision = 2 * b->_delta_y - b->_delta_x;
	while (++b->_xi < b->p2.x)
	{
		if (b->_decision <= 0)
			b->_decision += b->_delta_y;
		else
		{
			b->_decision += (b->_delta_y - b->_delta_x);
			++b->_yi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_8_4(t_bresenham *b)
{
	b->_decision = 2 * b->_delta_y + b->_delta_x;
	while (++b->_xi < b->p2.x)
	{
		if (b->_decision >= 0)
			b->_decision += b->_delta_y;
		else
		{
			b->_decision += (b->_delta_y + b->_delta_x);
			--b->_yi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_2_6(t_bresenham *b)
{
	b->_decision = 2 * b->_delta_x - b->_delta_y;
	while (++b->_yi < b->p2.y)
	{
		if (b->_decision <= 0)
			b->_decision += b->_delta_x;
		else
		{
			b->_decision += (b->_delta_x - b->_delta_y);
			++b->_xi;
		}
		bresenham_draw(b);
	}
}

void	bresenham_octante_7_3(t_bresenham *b)
{
	b->_decision = 2 * b->_delta_x + b->_delta_y;
	while (--b->_yi > b->p2.y)
	{
		if (b->_decision <= 0)
			b->_decision += b->_delta_x;
		else
		{
			b->_decision += (b->_delta_x + b->_delta_y);
			++b->_xi;
		}
		bresenham_draw(b);
	}
}
