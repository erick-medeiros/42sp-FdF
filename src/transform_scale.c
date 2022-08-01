/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/31 22:54:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_scale_x(t_line *line, float scale_factor)
{
	float	x1;
	float	x2;

	x1 = line->p1.x * scale_factor;
	x2 = line->p2.x * scale_factor;
	line->p1.x = (int)x1;
	line->p2.x = (int)x2;
}

void	transform_scale_y(t_line *line, float scale_factor)
{
	float	y1;
	float	y2;

	y1 = line->p1.y * scale_factor;
	y2 = line->p2.y * scale_factor;
	line->p1.y = (int)y1;
	line->p2.y = (int)y2;
}

void	transform_scale_z(t_line *line, float scale_factor)
{
	float	z1;
	float	z2;

	z1 = line->p1.z * scale_factor;
	z2 = line->p2.z * scale_factor;
	line->p1.z = (int)z1;
	line->p2.z = (int)z2;
}

void	transform_scale_z_specific(t_line *line, t_camera *camera)
{
	float	scale_z;

	if (camera->scale_z > 1000)
		camera->scale_z = 1000;
	if (camera->scale_z < -1000)
		camera->scale_z = -1000;
	scale_z = (float) camera->scale_z / 100;
	scale_z /= 2;
	transform_scale_z(line, scale_z);
}

void	transform_scale(t_line *line, t_camera *camera)
{
	float	scale_factor;

	if (camera->scale_factor > 1000)
		camera->scale_factor = 1000;
	if (camera->scale_factor < -1000)
		camera->scale_factor = -1000;
	scale_factor = (float) camera->scale_factor / 100;
	transform_scale_x(line, scale_factor);
	transform_scale_y(line, scale_factor);
	transform_scale_z(line, scale_factor);
}
