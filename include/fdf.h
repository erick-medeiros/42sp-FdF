/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/15 17:04:22 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		1120
# define WINDOW_HEIGHT		630
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

typedef struct s_fdf_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_fdf_point;

typedef struct s_fdf_map {
	t_fdf_point	**coordinates;
	int			max_x;
	int			max_y;
	int			max_z;
	int			min_z;
}	t_fdf_map;

typedef struct s_fdf_img {
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_fdf_img;

typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_fdf_img	img;
	t_fdf_map	map;
}	t_fdf;

// free {
void		free_filedata(char ***filedata);
void		free_coordinates(t_fdf_map	*map);
void		free_all(t_fdf *fdf);
// } free

// exit {
void		free_error_exit(t_fdf *fdf, int error_status);
void		error_exit(int error_status);
void		success_exit(int success_status);
// } exit

// handle_events {
int			handle_keypress(int keycode, t_fdf *fdf);
int			handle_expose(t_fdf *fdf);
// } handle_events

// read {
void		read_map(t_fdf *fdf, char *filepath);
// } read

// render {
void		update_image_pixel(t_fdf_img *img,
				int pixel_x, int pixel_y, int color);
void		render_map(t_fdf *fdf);
int			render(t_fdf *fdf);
// } render

void		init_fdf(t_fdf *fdf);

#endif