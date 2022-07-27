/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:19:48 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/27 23:34:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	update_image_pixel(t_img *img, int pixel_x, int pixel_y, int color)
{
	char	*pixel;
	int		shift_bits;

	if (pixel_x < 0 || pixel_x >= WINDOW_WIDTH)
		return ;
	if (pixel_y < 0 || pixel_y >= WINDOW_HEIGHT)
		return ;
	pixel = img->framebuffer;
	pixel += (pixel_y * img->size_line + pixel_x * (img->bits_per_pixel / 8));
	shift_bits = img->bits_per_pixel - 8;
	while (shift_bits >= 0)
	{
		if (img->endian == 1)
			*pixel++ = (color >> shift_bits) & 0xFF;
		else if (img->endian == 0)
			*pixel++ = (color >> (img->bits_per_pixel - 8 - shift_bits)) & 0xFF;
		shift_bits -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	while (pixel_y < WINDOW_HEIGHT)
	{
		pixel_x = 0;
		while (pixel_x < WINDOW_WIDTH)
		{
			update_image_pixel(img, pixel_x, pixel_y, color);
			pixel_x++;
		}
		pixel_y++;
	}
}

// fdf->camera.depth_z = fmax(fdf->map.delta_z, 
//	fmax(fdf->map.max_x, fdf->map.max_y));
// fdf->camera.depth_z = fdf->map.delta_z;

void	render_line(t_fdf *fdf, t_point *point1, t_point *point2)
{
	t_line		line;

	line.p1 = *point1;
	line.p2 = *point2;
	if (line.p1.z > 0)
		line.p1.color = C_MAGENTA;
	else
		line.p1.color = C_BLACK;
	if (line.p2.z > 0)
		line.p2.color = C_MAGENTA;
	else
		line.p2.color = C_BLACK;
	transform_scale_z(&line, 20);
	transform_scale(&line, fdf->camera.scale_factor);
	transform_rotate(&line, &fdf->camera);
	transform_translate_x(&line, fdf->camera.move_x);
	transform_translate_y(&line, fdf->camera.move_y);
	bresenham(fdf, &line);
}

void	menu(t_fdf *fdf);

int	render(t_fdf *fdf)
{
	if (fdf->win_ptr == NULL || fdf->img.img_ptr == NULL)
		return (1);
	render_background(&fdf->img, C_BLACK);
	render_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	return (0);
}
