/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:01:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/04 00:52:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	projection_perspective(t_line *line, int depth_z)
{
	int		focal_length;
	double	z_ave;

	transform_rotate_x(line, ANG_180_RADIAN);
	transform_rotate_y(line, ANG_180_RADIAN);
	focal_length = 1;
	z_ave = line->p1.z - depth_z;
	if (z_ave != 0)
	{
		line->p1.x = line->p1.x * focal_length / z_ave;
		line->p1.y = line->p1.y * focal_length / z_ave;
	}
	z_ave = line->p2.z - depth_z;
	if (z_ave != 0)
	{
		line->p2.x = line->p2.x * focal_length / z_ave;
		line->p2.y = line->p2.y * focal_length / z_ave;
	}
	transform_scale(line, depth_z);
}

static void	projection_isometric(t_line *line)
{
	t_point	p;
	double	angle_x;
	double	angle_y;
	double	angle_z;

	angle_x = ANG_30_RADIAN;
	angle_y = ANG_30_RADIAN + ANG_120_RADIAN;
	angle_z = ANG_30_RADIAN - ANG_120_RADIAN;
	p.x = line->p1.x;
	p.y = line->p1.y;
	p.z = line->p1.z;
	line->p1.x = p.x * cos(angle_x) + p.y * cos(angle_y) + p.z * cos(angle_z);
	line->p1.y = p.x * sin(angle_x) + p.y * sin(angle_y) + p.z * sin(angle_z);
	p.x = line->p2.x;
	p.y = line->p2.y;
	p.z = line->p2.z;
	line->p2.x = p.x * cos(angle_x) + p.y * cos(angle_y) + p.z * cos(angle_z);
	line->p2.y = p.x * sin(angle_x) + p.y * sin(angle_y) + p.z * sin(angle_z);
}

void	projection(t_line *line, t_fdf *fdf)
{
	if (fdf->camera.projection == ISOMETRIC)
		projection_isometric(line);
	else if (fdf->camera.projection == PERSPECTIVE)
	{
		projection_perspective(line, fdf->camera.depth_z);
	}
}
