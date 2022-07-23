/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:48:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/23 22:30:46 by eandre-f         ###   ########.fr       */
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

void	render_line(t_fdf *fdf, t_point *start, t_point *end)
{
	t_vector	vector;

	vector.x1 = start->x * fdf->view.scale_factor;
	vector.y1 = start->y * fdf->view.scale_factor;
	vector.z1 = start->z;
	vector.color1 = start->color;
	vector.x2 = end->x * fdf->view.scale_factor;
	vector.y2 = end->y * fdf->view.scale_factor;
	vector.z2 = end->z;
	vector.color2 = end->color;
	bresenham(fdf, &vector);
}

void	render_map(t_fdf *fdf)
{
	int	map_x;
	int	map_y;

	fdf->view.scale_factor = calculate_scale_factor(&fdf->map);
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
