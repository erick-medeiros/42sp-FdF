/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:24:27 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/01 11:45:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_bresenham(t_bresenham *b, t_point *p1, t_point *p2)
{
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
	init_color(&b->color, b->p1.color, b->p2.color);
}

void	bresenham_draw(t_bresenham *b)
{
	float	progress;
	int		color;

	if (abs(b->_delta_x) >= abs(b->_delta_y))
		progress = (float)(b->_xi - b->p1.x) / (float)b->_delta_x;
	else
		progress = (float)(b->_yi - b->p1.y) / (float)b->_delta_y;
	color = b->color.color1 + get_color_gradient(&b->color, progress);
	update_image_pixel(&b->fdf->img, b->_xi, b->_yi, color);
}

void	bresenham(t_fdf *fdf, t_point *p1, t_point *p2)
{
	t_bresenham	b;

	init_bresenham(&b, p1, p2);
	b.fdf = fdf;
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
}
