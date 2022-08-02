/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:49:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 14:17:16 by eandre-f         ###   ########.fr       */
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

static int	get_color_file(char *color)
{
	color = ft_strchr(color, ',');
	ft_tolower_str(&color);
	if (color)
		return (ft_atoi_base(&color[1], HEXADECIMAL_BASE));
	else
		return (-1);
}

static void	*set_coordinates(t_map *map, char ***filedata, int x, int y)
{
	map->coordinates = malloc(map->max_x * sizeof(t_point *));
	if (!map->coordinates)
		return (NULL);
	x = 0;
	while (x < map->max_x)
	{
		map->coordinates[x] = malloc(map->max_y * sizeof(t_point));
		if (map->coordinates[x] == NULL)
			return (NULL);
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
	return (NULL);
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
		while (filedata[y][x] != NULL)
		{
			map->max_z = fmax(ft_atoi(filedata[y][x]), map->max_z);
			map->min_z = fmin(ft_atoi(filedata[y][x]), map->min_z);
			x++;
		}
		if (map->max_x != x)
			perror("");
		y++;
	}
	map->max_y = y;
}

void	read_map(t_map *map, char *filepath)
{
	char	***filedata;

	filedata = read_file(filepath, NULL, 0, 0);
	if (filedata == NULL)
		error_exit(2);
	map->coordinates = NULL;
	get_max_values(map, filedata);
	set_coordinates(map, filedata, 0, 0);
	update_map_scale(map);
	free_filedata(filedata);
}
