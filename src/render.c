/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:19:48 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/10 22:29:37 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define WHITE_PIXEL 0xFFFFFF

void	update_image_pixel(t_fdf_img *img, int x, int y, int color)
{
	char	*pixel;
	int		shift_bits;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
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

void	render_background(t_fdf_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			update_image_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	render(t_fdf *fdf)
{
	if (fdf->win_ptr == NULL || fdf->img.img_ptr == NULL)
		return (1);
	render_background(&fdf->img, WHITE_PIXEL);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	return (0);
}
