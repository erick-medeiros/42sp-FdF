/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:01:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 19:45:30 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_projection_perspective_weak(t_line *line, t_camera *camera)
{
	int	focal_length;
	int	depth_z;

	focal_length = 1;
	transform_rotate_x(line, ANG_1_RADIAN * 5);
	depth_z = line->p1.z + camera->depth_z;
	line->p1.x = (line->p1.x * focal_length) / depth_z;
	line->p1.y = (line->p1.y * focal_length) / depth_z;
	// line->p1.y = line->p1.y * -1;
	depth_z = line->p2.z + camera->depth_z;
	line->p2.x = (line->p2.x * focal_length) / depth_z;
	line->p2.y = (line->p2.y * focal_length) / depth_z;
	// line->p2.y = line->p2.y * -1;
	transform_scale(line, depth_z);
}

void	transform_projection(t_line *line, t_camera *camera)
{
	transform_projection_perspective_weak(line, camera);
}
