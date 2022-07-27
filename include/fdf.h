/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/27 23:04:29 by eandre-f         ###   ########.fr       */
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
# define KEY_ESC		65307
# define KEY_PLUS1	61
# define KEY_PLUS2	65451
# define KEY_MINUS1	45
# define KEY_MINUS2	65453
# define KEY_LEFT		65361
# define KEY_RIGHT	65363
# define KEY_UP			65362
# define KEY_DOWN		65364
# define ANG_1_RADIAN		0.017453292519943
# define ANG_30_RADIAN	0.523598775598299
# define ANG_45_RADIAN	0.785398163397448
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
	int		delta_z;
}	t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*framebuffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_line {
	t_point		p1;
	t_point		p2;
}	t_line;

typedef struct s_camera {
	int		scale_factor;
	double	alpha;
	double	beta;
	double	gamma;
	int		move_x;
	int		move_y;
	int		depth_z;
}	t_camera;

typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	t_camera	camera;
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
void	error_exit(int error_status);
void	success_exit(int success_status);
void	free_error_exit(t_fdf *fdf, int error_status);
void	free_success_exit(t_fdf *fdf, int success_status);
// } exit

// handle_events {
int		handle_keypress(int keycode, t_fdf *fdf);
int		handle_x11_destroy_notify(t_fdf *fdf);
int		handle_expose(t_fdf *fdf);
// } handle_events

// fdf {
void	init_fdf(t_fdf *fdf);
int		calculate_scale_factor(t_map *map);
// } fdf

// read {
void	read_map(t_fdf *fdf, char *filepath);
// } read

// render {
void	update_image_pixel(t_img *img, int pixel_x, int pixel_y, int color);
void	render_line(t_fdf *fdf, t_point *point1, t_point *point2);
void	render_map(t_fdf *fdf);
int		render(t_fdf *fdf);
// } render

// transform_scale {
void	transform_scale(t_line *line, int scale_factor);
void	transform_scale_x(t_line *line, int scale_factor);
void	transform_scale_y(t_line *line, int scale_factor);
void	transform_scale_z(t_line *line, int scale_factor);
// } transform_scale

// transform_rotate {
void	transform_rotate(t_line *line, t_camera *camera);
void	transform_rotate_x(t_line *line, double angle);
void	transform_rotate_y(t_line *line, double angle);
void	transform_rotate_z(t_line *line, double angle);
// } transform_rotate

// transform_translate {
void	transform_translate_x(t_line *line, int motion_factor);
void	transform_translate_y(t_line *line, int motion_factor);
// } transform_translate

// transform_projection {
void	transform_projection(t_line *line, t_camera *camera);
// } transform_projection

// bresenham_line_algorithm {
void	bresenham(t_fdf *fdf, t_line *line);
void	bresenham_draw(t_bresenham *b);
void	bresenham_axis(t_bresenham *b);
void	bresenham_octante_1_5(t_bresenham *b);
void	bresenham_octante_8_4(t_bresenham *b);
void	bresenham_octante_2_6(t_bresenham *b);
void	bresenham_octante_7_3(t_bresenham *b);
// } bresenham_line_algorithm

#endif