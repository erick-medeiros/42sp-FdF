/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:17:14 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/12 02:53:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_filedata(char ***filedata)
{
	int	x;
	int	y;

	y = 0;
	while (filedata[y] != NULL)
	{
		x = 0;
		while (filedata[y][x] != NULL)
		{
			free(filedata[y][x]);
			x++;
		}
		free(filedata[y]);
		y++;
	}
	free(filedata);
}

void	free_coordinates(t_fdf_map	*map)
{
	int	x;

	if (!map->coordinates)
		return ;
	x = 0;
	while (x < map->max_x)
	{
		if (map->coordinates[x] != NULL)
			free(map->coordinates[x]);
		x++;
	}
	if (map->coordinates != NULL)
		free(map->coordinates);
}

void	free_all(t_fdf *fdf)
{
	if (fdf->img.img_ptr != NULL)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img_ptr);
	if (fdf->win_ptr != NULL)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr != NULL)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
	free_coordinates(&fdf->map);
}
