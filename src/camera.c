/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:21:18 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 17:22:09 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	system_coordinates(t_fdf *fdf, int size)
{
	t_point	point1;
	t_point	point2;
	int		scale_factor;
	int		scale_z;

	scale_factor = fdf->camera.scale_factor;
	scale_z = fdf->camera.scale_z;
	fdf->camera.scale_factor = 100;
	fdf->camera.scale_z = 100;
	fdf->camera.change_color = 0;
	init_point(&point1, C_RED);
	init_point(&point2, C_RED);
	point2.x = size;
	render_line(fdf, &point1, &point2);
	init_point(&point1, C_GREEN);
	init_point(&point2, C_GREEN);
	point2.y = size;
	render_line(fdf, &point1, &point2);
	init_point(&point1, C_BLUE);
	init_point(&point2, C_BLUE);
	point2.z = size;
	render_line(fdf, &point1, &point2);
	fdf->camera.scale_factor = scale_factor;
	fdf->camera.scale_z = scale_z;
}

void	camera_limits(t_camera *camera)
{
	if (camera->angle_x > ANG_360_RADIAN || camera->angle_x < -ANG_360_RADIAN)
		camera->angle_x = 0;
	if (camera->angle_y > ANG_360_RADIAN || camera->angle_y < -ANG_360_RADIAN)
		camera->angle_y = 0;
	if (camera->angle_z > ANG_360_RADIAN || camera->angle_z < -ANG_360_RADIAN)
		camera->angle_z = 0;
	if (camera->scale_factor > 1000)
		camera->scale_factor = 1000;
	if (camera->scale_factor < -1000)
		camera->scale_factor = -1000;
	if (camera->scale_z > 1000)
		camera->scale_z = 1000;
	if (camera->scale_z < -1000)
		camera->scale_z = -1000;
}

void	reset_camera(t_fdf *fdf)
{
	fdf->camera.scale_factor = fdf->map.map_scale;
	fdf->camera.scale_z = 100;
	fdf->camera.move_x = WINDOW_WIDTH / 2;
	fdf->camera.move_y = WINDOW_HEIGHT / 2;
	fdf->camera.angle_x = 0;
	fdf->camera.angle_y = 0;
	fdf->camera.angle_z = 0;
}
