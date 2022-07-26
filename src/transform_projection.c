/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:01:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 17:18:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_projection_perspective_weak(t_camera *camera, t_point *point)
{
	int	focal_length;
	int	depth_z;

	focal_length = 1;
	transform_rotate_x(point, ANG_1_RADIAN * 5);
	depth_z = point->z + camera->depth_z;
	point->x = (point->x * focal_length) / depth_z;
	point->y = (point->y * focal_length) / depth_z;
	// point->y = point->y * -1;
	transform_scale(point, depth_z);
}

void	transform_projection(t_camera *camera, t_point *point)
{
	transform_projection_perspective_weak(camera, point);
}
