/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:01:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/28 15:55:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	projection_perspective(t_line *line, t_camera *camera)
{
	int	focal_length;
	int	depth_z;

	focal_length = 1;
	depth_z = line->p1.z + camera->depth_z;
	line->p1.x = (line->p1.x * focal_length) / depth_z;
	line->p1.y = (line->p1.y * focal_length) / depth_z;
	depth_z = line->p2.z + camera->depth_z;
	line->p2.x = (line->p2.x * focal_length) / depth_z;
	line->p2.y = (line->p2.y * focal_length) / depth_z;
	transform_scale(line, camera->depth_z);
}

void	projection_isometric(t_line *line)
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

void	projection(t_line *line, t_camera *camera)
{
	if (camera->projection == ISOMETRIC)
		projection_isometric(line);
	else if (camera->projection == PERSPECTIVE)
		projection_perspective(line, camera);
}
