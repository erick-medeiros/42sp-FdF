/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/31 13:55:01 by eandre-f         ###   ########.fr       */
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
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

void	points_center(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	while (j < fdf->map.max_y)
	{
		i = 0;
		while (i < fdf->map.max_x)
		{
			fdf->map.coordinates[i][j].x -= fdf->map.max_x / 2;
			fdf->map.coordinates[i][j].y -= fdf->map.max_y / 2;
			i++;
		}
		j++;
	}
}

void	system_coordinates(t_fdf *fdf, int size)
{
	t_point	point1;
	t_point	point2;

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
}

void	render_map(t_fdf *fdf)
{
	int	map_x;
	int	map_y;

	fdf->camera.change_color = 1;
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
