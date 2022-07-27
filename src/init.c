/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:24:28 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/27 23:02:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_fdf(t_fdf *fdf)
{
	fdf->camera.scale_factor = 0;
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
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
