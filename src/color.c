/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:17:29 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 00:06:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	get_color_gradient(t_color *color, float gradient)
{
	int	color_r;
	int	color_g;
	int	color_b;

	color_r = color->delta_r * gradient;
	if (color_r > 255)
		color_r = 255;
	else if (color_r < -255)
		color_r = 0;
	color_g = color->delta_g * gradient;
	if (color_g > 255)
		color_g = 255;
	else if (color_g < -255)
		color_g = 0;
	color_b = color->delta_b * gradient;
	if (color_b > 255)
		color_b = 255;
	else if (color_b < -255)
		color_b = 0;
	return ((color_r << 16) + (color_g << 8) + color_b);
}

static	int	point_gradient_3(float gradient, int c1, int c2, int c3)
{
	t_color	color;
	int		color1;
	int		color2;

	color1 = c1;
	color2 = c2;
	if (gradient >= 0.5)
	{
		color1 = c2;
		color2 = c3;
	}
	init_color(&color, color1, color2);
	return (color1 + get_color_gradient(&color, gradient));
}

void	set_color_point(t_fdf *fdf, t_point *point)
{
	float	gradient;
	float	delta_z;

	if (fdf->camera.color_palette == COLORPALETTE0)
		point->color = PALETTE0_COLOR1;
	else if (fdf->camera.color_palette == COLORPALETTE1)
	{
		if (point->color == -1)
			point->color = PALETTE1_COLOR1;
	}
	else if (fdf->camera.color_palette == COLORPALETTE2)
	{
		point->color = PALETTE2_COLOR1;
		if (point->z == 0)
			point->color = PALETTE2_COLOR2;
	}
	else if (fdf->camera.color_palette == COLORPALETTE3)
	{
		delta_z = fdf->map.max_z - fdf->map.min_z;
		gradient = (point->z - fdf->map.min_z) / delta_z;
		point->color = point_gradient_3(gradient,
				PALETTE3_COLOR1, PALETTE3_COLOR2, PALETTE3_COLOR3);
	}
}
