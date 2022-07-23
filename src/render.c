/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:19:48 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/23 22:16:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	update_image_pixel(t_img *img, int pixel_x, int pixel_y, int color)
{
	char	*pixel;
	int		shift_bits;

	if (pixel_x < 0 || pixel_x > WINDOW_WIDTH)
		return ;
	if (pixel_y < 0 || pixel_y > WINDOW_HEIGHT)
		return ;
	pixel = img->data + (pixel_y * img->size_line + pixel_x * (img->bpp / 8));
	shift_bits = img->bpp - 8;
	while (shift_bits >= 0)
	{
		if (img->endian == 1)
			*pixel++ = (color >> shift_bits) & 0xFF;
		else if (img->endian == 0)
			*pixel++ = (color >> (img->bpp - 8 - shift_bits)) & 0xFF;
		shift_bits -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	while (pixel_y <= WINDOW_HEIGHT)
	{
		pixel_x = 0;
		while (pixel_x <= WINDOW_WIDTH)
		{
			update_image_pixel(img, pixel_x, pixel_y, color);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	draw_triangle(t_fdf *fdf)
{
	bresenham(fdf, &((t_vector){200, 500, 0, C_BLUE, 800, 500, 0, C_RED}));
	bresenham(fdf, &((t_vector){200, 500, 0, C_BLUE, 500, 100, 0, C_GREEN}));
	bresenham(fdf, &((t_vector){500, 100, 0, C_GREEN, 800, 500, 0, C_RED}));
}

int	render(t_fdf *fdf)
{
	if (fdf->win_ptr == NULL || fdf->img.img_ptr == NULL)
		return (1);
	render_background(&fdf->img, C_BLACK);
	render_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	return (0);
}
