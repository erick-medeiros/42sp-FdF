/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:49:26 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/15 15:13:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define HEX_L_BASE	"0123456789abcdef"

static char	***read_file(char *pathname, char *line, int row, int fd)
{
	char	***filedata;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	row = 0;
	ft_strupd(&line, get_next_line(fd));
	while (line != NULL && ++row)
		ft_strupd(&line, get_next_line(fd));
	close(fd);
	fd = open(pathname, O_RDONLY);
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
		return (ft_atoi_base(&color[1], HEX_L_BASE));
	else
		return (-1);
}

static void	*set_coordinates(t_fdf_map *map, char ***s, int x, int y)
{
	map->coordinates = malloc(map->max_x * sizeof(t_fdf_point *));
	if (!map->coordinates)
		return (NULL);
	x = 0;
	while (x < map->max_x)
	{
		map->coordinates[x] = malloc(map->max_y * sizeof(t_fdf_point));
		if (map->coordinates[x] == NULL)
			return (NULL);
		y = 0;
		while (y < map->max_y)
		{
			map->coordinates[x][y].x = x;
			map->coordinates[x][y].y = y;
			map->coordinates[x][y].z = ft_atoi(s[y][x]);
			map->coordinates[x][y].color = get_color_file(s[y][x]);
			y++;
		}
		x++;
	}
	return (NULL);
}

static void	get_max_values(t_fdf *fdf, char ***filedata)
{
	int	x;
	int	y;

	fdf->map.max_x = 0;
	while (filedata[0][fdf->map.max_x] != NULL)
		fdf->map.max_x++;
	y = 0;
	fdf->map.max_z = 0;
	fdf->map.min_z = 0;
	while (filedata[y] != NULL)
	{
		x = 0;
		while (filedata[y][x] != NULL)
		{
			fdf->map.max_z = fmax(ft_atoi(filedata[y][x]), fdf->map.max_z);
			fdf->map.min_z = fmin(ft_atoi(filedata[y][x]), fdf->map.min_z);
			x++;
		}
		if (fdf->map.max_x != x)
			perror("");
		y++;
	}
	fdf->map.max_y = y;
}

void	read_map(t_fdf *fdf, char *pathname)
{
	char		***filedata;

	filedata = read_file(pathname, NULL, 0, 0);
	if (filedata == NULL)
		free_error_exit(fdf, 2);
	get_max_values(fdf, filedata);
	set_coordinates(&fdf->map, filedata, 0, 0);
	free_filedata(filedata);
}
