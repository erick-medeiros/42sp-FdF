/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 00:25:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	calculate_map_scale(t_map *map)
{
	int	scale_x;
	int	scale_y;
	int	map_scale;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	map_scale = fmin(scale_x, scale_y);
	if (map_scale < 4)
		return (2);
	return (map_scale / 2);
}

void	update_map_scale(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->map.map_scale = calculate_map_scale(&fdf->map);
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
	int		scale_factor;
	int		scale_z;

	scale_factor = fdf->camera.scale_factor;
	scale_z = fdf->camera.scale_z;
	fdf->camera.scale_factor = 100;
	fdf->camera.scale_z = 100;
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
	fdf->camera.scale_factor = scale_factor;
	fdf->camera.scale_z = scale_z;
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
