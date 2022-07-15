/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/15 17:05:01 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	calculate_scale_factor(t_fdf_map *map)
{
	int	scale_x;
	int	scale_y;
	int	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = fmin(scale_x, scale_y);
	return (scale_factor);
}

void	render_to_scale(t_fdf *fdf, int map_x, int map_y, int scale_factor)
{
	int	init_x;
	int	init_y;
	int	pixel_x;
	int	pixel_y;

	init_x = map_x * scale_factor;
	init_y = map_y * scale_factor;
	pixel_y = init_y;
	while (pixel_y <= WINDOW_HEIGHT && pixel_y <= init_y + scale_factor)
	{
		pixel_x = init_x;
		while (pixel_x <= WINDOW_WIDTH && pixel_x <= init_x + scale_factor)
		{
			update_image_pixel(&fdf->img, pixel_x, pixel_y, WHITE_PIXEL);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	render_borders(t_fdf *fdf, int map_x, int map_y, int scale_factor)
{
	int	init_x;
	int	init_y;
	int	pixel_x;
	int	pixel_y;

	init_x = map_x * scale_factor;
	init_y = map_y * scale_factor;
	pixel_y = init_y;
	while (pixel_y <= WINDOW_HEIGHT && pixel_y <= init_y + scale_factor)
	{
		pixel_x = init_x;
		while (pixel_x <= WINDOW_WIDTH && pixel_x <= init_x + scale_factor)
		{
			if (pixel_y == init_y || pixel_y == init_y + scale_factor)
				update_image_pixel(&fdf->img, pixel_x, pixel_y, WHITE_PIXEL);
			if (pixel_x == init_x || pixel_x == init_x + scale_factor)
				update_image_pixel(&fdf->img, pixel_x, pixel_y, WHITE_PIXEL);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	render_map(t_fdf *fdf)
{
	int	map_x;
	int	map_y;
	int	scale_factor;

	scale_factor = calculate_scale_factor(&fdf->map);
	map_y = 0;
	while (map_y < fdf->map.max_y)
	{
		map_x = 0;
		while (map_x < fdf->map.max_x)
		{
			render_borders(fdf, map_x, map_y, scale_factor);
			if (fdf->map.coordinates[map_x][map_y].z > 0)
				render_to_scale(fdf, map_x, map_y, scale_factor);
			map_x++;
		}
		map_y++;
	}
}
