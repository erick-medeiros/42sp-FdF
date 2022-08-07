/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:24:28 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 14:27:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_fdf(t_fdf *fdf)
{
	init_camera(fdf);
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

void	init_camera(t_fdf *fdf)
{
	fdf->camera.scale_factor = fdf->map.map_scale;
	fdf->camera.scale_z = 100;
	fdf->camera.depth_z = fmax((fdf->map.max_z - fdf->map.min_z), \
		fmax(fdf->map.max_x, fdf->map.max_y));
	fdf->camera.projection = ISOMETRIC;
	fdf->camera.color_palette = COLORPALETTE0;
	fdf->camera.show_info = 1;
	fdf->camera.show_coord = -1;
	fdf->camera.change_color = 1;
	fdf->camera.angle_x = 0;
	fdf->camera.angle_y = 0;
	fdf->camera.angle_z = 0;
	fdf->camera.move_x = WINDOW_WIDTH / 2;
	fdf->camera.move_y = WINDOW_HEIGHT / 2;
}

void	init_point(t_point *point, int color)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = color;
}

void	init_color(t_color *color, int color1, int color2)
{
	int	c1;
	int	c2;

	color->color1 = color1;
	color->color2 = color2;
	c1 = (C_RED & color1) >> 16;
	c2 = (C_RED & color2) >> 16;
	color->delta_r = c2 - c1;
	c1 = (C_GREEN & color1) >> 8;
	c2 = (C_GREEN & color2) >> 8;
	color->delta_g = c2 - c1;
	c1 = C_BLUE & color1;
	c2 = C_BLUE & color2;
	color->delta_b = c2 - c1;
}

void	init_line(t_fdf *fdf, t_line *line, t_point *p1, t_point *p2)
{
	line->p1 = *p1;
	line->p2 = *p2;
	line->show = 1;
	if (fdf->camera.change_color)
	{
		set_color_point(fdf, &line->p1);
		set_color_point(fdf, &line->p2);
	}
}
