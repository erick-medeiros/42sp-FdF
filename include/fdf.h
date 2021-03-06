/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/23 22:31:20 by eandre-f         ###   ########.fr       */
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
# define HEXADECIMAL_BASE	"0123456789abcdef"
# define C_WHITE		0xFFFFFF
# define C_BLACK		0x000000
# define C_RED			0xFF0000
# define C_GREEN		0x00FF00
# define C_BLUE			0x0000FF
# define C_YELLOW		0xFFFF00
# define C_CYAN			0x00FFFF
# define C_MAGENTA	0xFF00FF

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map {
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_vector {
	int	x1;
	int	y1;
	int	z1;
	int	color1;
	int	x2;
	int	y2;
	int	z2;
	int	color2;
}	t_vector;

typedef struct s_view {
	int		scale_factor;
	float	alpha;
	float	beta;
	float	gamma;
}	t_view;

typedef struct s_fdf {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
	t_view	view;
}	t_fdf;

typedef struct s_bresenham {
	t_fdf	*fdf;
	int		x1;
	int		y1;
	int		color1;
	int		x2;
	int		y2;
	int		color2;
	int		_xi;
	int		_yi;
	int		_delta_x;
	int		_delta_y;
	int		_decision;
	int		_delta_r;
	int		_delta_g;
	int		_delta_b;
}	t_bresenham;

// free {
void	free_filedata(char ***filedata);
void	free_coordinates(t_map	*map);
void	free_all(t_fdf *fdf);
// } free

// exit {
void	free_error_exit(t_fdf *fdf, int error_status);
void	error_exit(int error_status);
void	success_exit(int success_status);
// } exit

// handle_events {
int		handle_keypress(int keycode, t_fdf *fdf);
int		handle_expose(t_fdf *fdf);
// } handle_events

// fdf {
void	init_fdf(t_fdf *fdf);
// } fdf

// read {
void	read_map(t_fdf *fdf, char *filepath);
// } read

// render {
void	update_image_pixel(t_img *img, int pixel_x, int pixel_y, int color);
void	render_map(t_fdf *fdf);
int		render(t_fdf *fdf);
// } render

// bresenham_line_algorithm {
void	bresenham(t_fdf *fdf, t_vector *vector);
void	bresenham_draw(t_bresenham *b);
void	bresenham_axis(t_bresenham *b);
void	bresenham_octante_1_5(t_bresenham *b);
void	bresenham_octante_8_4(t_bresenham *b);
void	bresenham_octante_2_6(t_bresenham *b);
void	bresenham_octante_7_3(t_bresenham *b);
// } bresenham_line_algorithm

#endif