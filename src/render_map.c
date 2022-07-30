/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/30 13:30:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	calculate_scale_factor(t_map *map)
{
	int	scale_x;
	int	scale_y;
	int	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = fmin(scale_x, scale_y);
	return (scale_factor);
}

void	system_coordinates(t_fdf *fdf, int size)
{
	t_line	line;

	init_point(&line.p1, C_RED);
	init_point(&line.p2, C_RED);
	line.p2.x = size;
	transform_rotate(&line, &fdf->camera);
	transform_translate(&line, &fdf->camera);
	bresenham(fdf, &line.p1, &line.p2);
	init_point(&line.p1, C_GREEN);
	init_point(&line.p2, C_GREEN);
	line.p2.y = size;
	transform_rotate(&line, &fdf->camera);
	transform_translate(&line, &fdf->camera);
	bresenham(fdf, &line.p1, &line.p2);
	init_point(&line.p1, C_BLUE);
	init_point(&line.p2, C_BLUE);
	line.p2.z = size;
	transform_rotate(&line, &fdf->camera);
	transform_translate(&line, &fdf->camera);
	bresenham(fdf, &line.p1, &line.p2);
}

void	render_map(t_fdf *fdf)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (map_y < fdf->map.max_y)
	{
		map_x = 0;
		while (map_x < fdf->map.max_x)
		{
			if (map_x < fdf->map.max_x - 1)
				render_line(fdf, &fdf->map.coordinates[map_x][map_y],
					&fdf->map.coordinates[map_x + 1][map_y]);
			if (map_y < fdf->map.max_y - 1)
				render_line(fdf, &fdf->map.coordinates[map_x][map_y],
					&fdf->map.coordinates[map_x][map_y + 1]);
			map_x++;
		}
		map_y++;
	}
}
