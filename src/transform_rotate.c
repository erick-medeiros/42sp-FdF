/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 00:37:09 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_rotate_x(t_line *line, double angle)
{
	t_point	point;

	point.y = line->p1.y;
	point.z = line->p1.z;
	line->p1.y = point.y * cos(angle) - point.z * sin(angle);
	line->p1.z = point.y * sin(angle) + point.z * cos(angle);
	point.y = line->p2.y;
	point.z = line->p2.z;
	line->p2.y = point.y * cos(angle) - point.z * sin(angle);
	line->p2.z = point.y * sin(angle) + point.z * cos(angle);
}

void	transform_rotate_y(t_line *line, double angle)
{
	t_point	point;

	point.x = line->p1.x;
	point.z = line->p1.z;
	line->p1.x = point.x * cos(angle) + point.z * sin(angle);
	line->p1.z = -point.x * sin(angle) + point.z * cos(angle);
	point.x = line->p2.x;
	point.z = line->p2.z;
	line->p2.x = point.x * cos(angle) + point.z * sin(angle);
	line->p2.z = -point.x * sin(angle) + point.z * cos(angle);
}

void	transform_rotate_z(t_line *line, double angle)
{
	t_point	point;

	point.x = line->p1.x;
	point.y = line->p1.y;
	line->p1.x = point.x * cos(angle) - point.y * sin(angle);
	line->p1.y = point.x * sin(angle) + point.y * cos(angle);
	point.x = line->p2.x;
	point.y = line->p2.y;
	line->p2.x = point.x * cos(angle) - point.y * sin(angle);
	line->p2.y = point.x * sin(angle) + point.y * cos(angle);
}

void	transform_rotate(t_line *line, t_camera *camera)
{
	if (camera->angle_x > ANG_360_RADIAN || camera->angle_x < -ANG_360_RADIAN)
		camera->angle_x = 0;
	if (camera->angle_y > ANG_360_RADIAN || camera->angle_y < -ANG_360_RADIAN)
		camera->angle_y = 0;
	if (camera->angle_z > ANG_360_RADIAN || camera->angle_z < -ANG_360_RADIAN)
		camera->angle_z = 0;
	transform_rotate_x(line, camera->angle_x);
	transform_rotate_y(line, camera->angle_y);
	transform_rotate_z(line, camera->angle_z);
}
