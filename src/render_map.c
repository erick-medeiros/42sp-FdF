/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/16 01:38:31 by eandre-f         ###   ########.fr       */
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

void	render_line(t_fdf *fdf, t_fdf_point *start, t_fdf_point *end, int scale_factor)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = start->y * scale_factor;
	while (pixel_y <= end->y * scale_factor)
	{
		pixel_x = start->x * scale_factor;
		while (pixel_x <= end->x * scale_factor)
		{
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
			if (map_x < fdf->map.max_x - 1)
				render_line(fdf, &fdf->map.coordinates[map_x][map_y],
					&fdf->map.coordinates[map_x + 1][map_y], scale_factor);
			if (map_y < fdf->map.max_y - 1)
				render_line(fdf, &fdf->map.coordinates[map_x][map_y],
					&fdf->map.coordinates[map_x][map_y + 1], scale_factor);
			map_x++;
		}
		map_y++;
	}
}
