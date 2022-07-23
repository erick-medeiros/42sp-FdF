/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:24:27 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/23 22:15:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_bresenham(t_bresenham *b, t_vector *v)
{
	b->x1 = v->x1;
	b->y1 = v->y1;
	b->color1 = v->color1;
	b->x2 = v->x2;
	b->y2 = v->y2;
	b->color2 = v->color2;
	if (v->x1 > v->x2 || (v->x1 == v->x2 && v->y1 > v->y2))
	{
		b->x1 = v->x2;
		b->y1 = v->y2;
		b->color1 = v->color2;
		b->x2 = v->x1;
		b->y2 = v->y1;
		b->color2 = v->color1;
	}
	b->_xi = b->x1;
	b->_yi = b->y1;
	b->_delta_x = b->x2 - b->x1;
	b->_delta_y = b->y2 - b->y1;
	b->_delta_r = (((C_RED & b->color2) >> 16) - ((C_RED & b->color1) >> 16));
	b->_delta_g = (((C_GREEN & b->color2) >> 8) - ((C_GREEN & b->color1) >> 8));
	b->_delta_b = (((C_BLUE & b->color2)) - ((C_BLUE & b->color1)));
}

void	bresenham_draw(t_bresenham *b)
{
	float	progress;
	int		_r;
	int		_g;
	int		_b;
	int		color_i;

	if (abs(b->_delta_x) >= abs(b->_delta_y))
		progress = (float)(b->_xi - b->x1) / (float)b->_delta_x;
	else
		progress = (float)(b->_yi - b->y1) / (float)b->_delta_y;
	_r = b->_delta_r * progress;
	if (_r > 255)
		_r = 255;
	_g = b->_delta_g * progress;
	if (_g > 255)
		_g = 255;
	_b = b->_delta_b * progress;
	if (_b > 255)
		_b = 255;
	color_i = b->color1 + (_r << 16) + (_g << 8) + _b;
	update_image_pixel(&b->fdf->img, b->_xi, b->_yi, color_i);
}

void	bresenham(t_fdf *fdf, t_vector *vector)
{
	t_bresenham	b;

	init_bresenham(&b, vector);
	b.fdf = fdf;
	update_image_pixel(&fdf->img, b.x1, b.y1, b.color1);
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
	update_image_pixel(&fdf->img, b.x2, b.y2, b.color2);
}
