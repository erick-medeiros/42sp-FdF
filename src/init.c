/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:24:28 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/30 12:45:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_fdf(t_fdf *fdf)
{
	fdf->camera.scale_factor = 0;
	fdf->camera.projection = TOP;
	fdf->camera.show_info = 1;
	fdf->camera.show_coord = 1;
	fdf->camera.scale_z = 1;
	fdf->camera.angle_x = 0;
	fdf->camera.angle_y = 0;
	fdf->camera.angle_z = 0;
	fdf->camera.move_x = 0;
	fdf->camera.move_y = 0;
	fdf->map.coordinates = NULL;
	fdf->win_ptr = NULL;
	fdf->img.img_ptr = NULL;
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		free_error_exit(fdf, 3);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	if (fdf->win_ptr == NULL)
		free_error_exit(fdf, 3);
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->img.img_ptr == NULL)
		free_error_exit(fdf, 3);
	fdf->img.framebuffer = mlx_get_data_addr(fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.size_line, &fdf->img.endian);
}

void	init_point(t_point *point, int color)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = color;
}

void	init_line(t_fdf *fdf, t_line *line, t_point *p1, t_point *p2)
{
	line->p1 = *p1;
	line->p2 = *p2;
	if (line->p1.z > 0)
		line->p1.color = C_MAGENTA;
	else
		line->p1.color = C_WHITE;
	if (line->p2.z > 0)
		line->p2.color = C_MAGENTA;
	else
		line->p2.color = C_WHITE;
	transform_scale_z(line, fdf->camera.scale_z);
	line->depth_z = fmax((fdf->map.max_z - fdf->map.min_z), \
		fmax(fdf->map.max_x, fdf->map.max_y));
}
