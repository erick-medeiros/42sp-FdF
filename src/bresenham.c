/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:24:27 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/03 22:23:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham_draw(t_bresenham *b)
{
	float	progress;
	int		color;

	if (abs(b->delta_x) >= abs(b->delta_y))
		progress = (float)(b->xi - b->p1.x) / (float)b->delta_x;
	else
		progress = (float)(b->yi - b->p1.y) / (float)b->delta_y;
	color = b->color.color1 + get_color_gradient(&b->color, progress);
	update_image_pixel(&b->fdf->img, b->xi, b->yi, color);
}

void	bresenham_axis(t_bresenham *b)
{
	if (b->delta_x == 0 && b->delta_y == 0)
		return ;
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

void	bresenham(t_fdf *fdf, t_point *p1, t_point *p2)
{
	t_bresenham	b;

	p1->x = (int)p1->x;
	p1->y = (int)p1->y;
	p2->x = (int)p2->x;
	p2->y = (int)p2->y;
	b.p1 = *p1;
	b.p2 = *p2;
	if (p1->x > p2->x || (p1->x == p2->x && p1->y > p2->y))
	{
		b.p1 = *p2;
		b.p2 = *p1;
	}
	b.xi = b.p1.x;
	b.yi = b.p1.y;
	b.delta_x = b.p2.x - b.p1.x;
	b.delta_y = b.p2.y - b.p1.y;
	init_color(&b.color, b.p1.color, b.p2.color);
	b.fdf = fdf;
	if (b.delta_x == 0 || b.delta_y == 0 || abs(b.delta_x) == abs(b.delta_y))
		bresenham_axis(&b);
	else
		bresenham_octantes(&b);
}
