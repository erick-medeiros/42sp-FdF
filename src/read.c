/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:49:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 17:14:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static char	***read_file(char *filepath, char *line, int row, int fd)
{
	char	***filedata;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	row = 0;
	ft_strupd(&line, get_next_line(fd));
	while (line != NULL && ++row)
		ft_strupd(&line, get_next_line(fd));
	close(fd);
	fd = open(filepath, O_RDONLY);
	filedata = malloc((row + 1) * sizeof(char **));
	if (fd < 0 || filedata == NULL)
		return (NULL);
	row = 0;
	while (1)
	{
		ft_strupd(&line, get_next_line(fd));
		if (line == NULL)
			break ;
		filedata[row++] = ft_split(line, ' ');
	}
	filedata[row] = NULL;
	close(fd);
	return (filedata);
}

static void	get_max_values(t_map *map, char ***filedata)
{
	int	x;
	int	y;

	map->max_x = 0;
	while (filedata[0][map->max_x] != NULL)
		map->max_x++;
	y = 0;
	map->max_z = 0;
	map->min_z = 0;
	while (filedata[y] != NULL)
	{
		x = 0;
		if (!ft_isprint(filedata[y][x][0]))
			free_filedata_error_exit(filedata, 2);
		while (filedata[y][x] != NULL)
		{
			map->max_z = fmax(ft_atoi(filedata[y][x]), map->max_z);
			map->min_z = fmin(ft_atoi(filedata[y][x]), map->min_z);
			x++;
		}
		if (map->max_x > x)
			free_filedata_error_exit(filedata, 4);
		y++;
	}
	map->max_y = y;
}

static void	set_coordinates(t_map *map, char ***filedata, int x, int y)
{
	map->coordinates = malloc(map->max_x * sizeof(t_point *));
	if (!map->coordinates)
		free_map_error_exit(map, 5);
	x = 0;
	while (x < map->max_x)
	{
		map->coordinates[x] = malloc(map->max_y * sizeof(t_point));
		if (map->coordinates[x] == NULL)
			free_map_error_exit(map, 5);
		y = 0;
		while (y < map->max_y)
		{
			map->coordinates[x][y].x = x;
			map->coordinates[x][y].y = y;
			map->coordinates[x][y].z = ft_atoi(filedata[y][x]);
			map->coordinates[x][y].color = get_color_file(filedata[y][x]);
			y++;
		}
		x++;
	}
}

static void	update_map_scale(t_map *map)
{
	int	i;
	int	j;
	int	scale_x;
	int	scale_y;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	map->map_scale = fmin(scale_x, scale_y);
	if (map->map_scale < 4)
		map->map_scale = 2;
	else
		map->map_scale /= 2;
	j = 0;
	while (j < map->max_y)
	{
		i = 0;
		while (i < map->max_x)
		{
			map->coordinates[i][j].x -= map->max_x / 2;
			map->coordinates[i][j].y -= map->max_y / 2;
			i++;
		}
		j++;
	}
}

void	read_map(t_map *map, char *filepath)
{
	char	***filedata;

	map->coordinates = NULL;
	filedata = read_file(filepath, NULL, 0, 0);
	if (filedata == NULL)
		error_exit(2);
	if (filedata[0] == NULL)
		free_filedata_error_exit(filedata, 2);
	get_max_values(map, filedata);
	if (map->max_x == 0 || map->max_y == 0)
		free_filedata_error_exit(filedata, 4);
	set_coordinates(map, filedata, 0, 0);
	update_map_scale(map);
	free_filedata(filedata);
}
