/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:24:27 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/28 15:51:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_bresenham(t_bresenham *b, t_point *p1, t_point *p2)
{
	int	color1;
	int	color2;

	b->p1 = *p1;
	b->p2 = *p2;
	if (p1->x > p2->x || (p1->x == p2->x && p1->y > p2->y))
	{
		b->p1 = *p2;
		b->p2 = *p1;
	}
	b->_xi = b->p1.x;
	b->_yi = b->p1.y;
	b->_delta_x = b->p2.x - b->p1.x;
	b->_delta_y = b->p2.y - b->p1.y;
	color1 = b->p1.color;
	color2 = b->p2.color;
	b->_delta_r = (((C_RED & color2) >> 16) - ((C_RED & color1) >> 16));
	b->_delta_g = (((C_GREEN & color2) >> 8) - ((C_GREEN & color1) >> 8));
	b->_delta_b = (((C_BLUE & color2)) - ((C_BLUE & color1)));
}

void	bresenham_draw(t_bresenham *b)
{
	float	progress;
	int		_r;
	int		_g;
	int		_b;
	int		color_i;

	if (abs(b->_delta_x) >= abs(b->_delta_y))
		progress = (float)(b->_xi - b->p1.x) / (float)b->_delta_x;
	else
		progress = (float)(b->_yi - b->p1.y) / (float)b->_delta_y;
	_r = b->_delta_r * progress;
	if (_r > 255)
		_r = 255;
	_g = b->_delta_g * progress;
	if (_g > 255)
		_g = 255;
	_b = b->_delta_b * progress;
	if (_b > 255)
		_b = 255;
	color_i = b->p1.color + (_r << 16) + (_g << 8) + _b;
	update_image_pixel(&b->fdf->img, b->_xi, b->_yi, color_i);
}

void	bresenham(t_fdf *fdf, t_point *p1, t_point *p2)
{
	t_bresenham	b;

	init_bresenham(&b, p1, p2);
	b.fdf = fdf;
	update_image_pixel(&fdf->img, p1->x, p1->y, b.color1);
	if (b._delta_x == 0 && b._delta_y == 0)
		return ;
	if (b._delta_x == 0 || b._delta_y == 0
		|| abs(b._delta_x) == abs(b._delta_y))
		bresenham_axis(&b);
	else if ((abs(b._delta_x) > abs(b._delta_y)) && (b._delta_y > 0))
		bresenham_octante_1_5(&b);
	else if ((abs(b._delta_x) > abs(b._delta_y)) && (b._delta_y < 0))
		bresenham_octante_8_4(&b);
	else if ((abs(b._delta_x) < abs(b._delta_y)) && (b._delta_y > 0))
		bresenham_octante_2_6(&b);
	else if ((abs(b._delta_x) < abs(b._delta_y)) && (b._delta_y < 0))
		bresenham_octante_7_3(&b);
	update_image_pixel(&fdf->img, p2->x, p2->y, b.color2);
}
