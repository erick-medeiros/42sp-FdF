/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 17:28:18 by eandre-f         ###   ########.fr       */
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
# define WINDOW_WIDTH		1280
# define WINDOW_HEIGHT		720
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
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_Q			113
# define KEY_E			101
# define KEY_I			105
# define KEY_P			112
# define KEY_T			116
# define KEY_DOT		46
# define KEY_C			99
# define KEY_R			114
# define KEY_Z			122
# define KEY_X			120
# define KEY_O			111
# define KEY_L			108
# define ANG_1_RADIAN		0.017453292519943
# define ANG_30_RADIAN	0.523598775598299
# define ANG_120_RADIAN	2.094395102393195
# define ANG_180_RADIAN 3.141592653589793
# define ANG_360_RADIAN	6.283185307179586
# define C_WHITE		0xFFFFFF
# define C_BLACK		0x000000
# define C_RED			0xFF0000
# define C_GREEN		0x00FF00
# define C_BLUE			0x0000FF
# define C_YELLOW		0xFFFF00
# define C_CYAN			0x00FFFF
# define C_MAGENTA	0xFF00FF
# define C_VIOLET		0x3E0694
# define DEFAULT_COLOR		C_WHITE
# define HIGHLIGHT_COLOR	C_YELLOW
# define BACKGROUND_COLOR	C_BLACK
# define PALETTE0_COLOR1 	DEFAULT_COLOR
# define PALETTE1_COLOR1 	C_VIOLET
# define PALETTE1_COLOR2 	BACKGROUND_COLOR
# define PALETTE2_COLOR1 	C_MAGENTA
# define PALETTE2_COLOR2 	C_BLUE
# define PALETTE2_COLOR3 	C_CYAN
# define PALETTE3_COLOR1 	C_GREEN

enum e_projection {
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_colorpalette {
	COLORPALETTE0,
	COLORPALETTE1,
	COLORPALETTE2,
	COLORPALETTE3
};

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map {
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
	int		map_scale;
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
	short		show;
}	t_line;

typedef struct s_camera {
	int		projection;
	int		show_info;
	int		show_coord;
	int		color_palette;
	int		change_color;
	int		scale_factor;
	int		scale_z;
	int		depth_z;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		move_x;
	int		move_y;
}	t_camera;

typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	t_camera	camera;
}	t_fdf;

typedef struct s_color
{
	int	color1;
	int	color2;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

typedef struct s_bresenham {
	t_fdf	*fdf;
	t_point	p1;
	t_point	p2;
	t_color	color;
	int		xi;
	int		yi;
	int		delta_x;
	int		delta_y;
	int		error;
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
void	free_filedata_error_exit(char ***filedata, int error_status);
void	free_map_error_exit(t_map *map, int error_status);
// } exit

// handle_events {
int		handle_exit(t_fdf *fdf);
int		handle_keypress(int keycode, t_fdf *fdf);
int		handle_keypress_transform(int keycode, t_fdf *fdf);
void	handle_keypress_color(t_fdf *fdf);
int		handle_expose(t_fdf *fdf);
// } handle_events

// init {
void	init_fdf(t_fdf *fdf);
void	init_camera(t_fdf *fdf);
void	init_point(t_point *point, int color);
void	init_color(t_color *color, int color1, int color2);
void	init_line(t_fdf *fdf, t_line *line, t_point *p1, t_point *p2);
// } init

// read {
void	read_map(t_map *map, char *filepath);
// } read

// camera {
void	system_coordinates(t_fdf *fdf, int size);
void	camera_limits(t_camera *camera);
void	reset_camera(t_fdf *fdf);
// } camera

// render {
void	update_image_pixel(t_img *img, int pixel_x, int pixel_y, int color);
void	render_line(t_fdf *fdf, t_point *point1, t_point *point2);
void	render_map(t_fdf *fdf);
int		render(t_fdf *fdf);
void	instructions(t_fdf *fdf);
// } render

// transform {
void	transform_scale(t_line *line, int scale_factor);
void	transform_scale_z(t_line *line, int scale_z);
void	transform_rotate(t_line *line, t_camera *camera);
void	transform_rotate_x(t_line *line, double angle);
void	transform_rotate_y(t_line *line, double angle);
void	transform_rotate_z(t_line *line, double angle);
void	transform_translate(t_line *line, t_camera *camera);
void	transform_translate_z(t_line *line, int move_z);
// } transform

// projection {
void	projection(t_line *line, t_fdf *fdf);
// } projection

// color {
int		get_color_file(char *color);
int		get_color_gradient(t_color *color, float gradient);
void	set_color_point(t_fdf *fdf, t_point *point);
// } color

// clipping {
void	camera_clipping(t_line *line, double *z1_distance, double *z2_distance);
void	cohensutherland_clipping(t_line *line);
// } clipping

// bresenham_line_algorithm {
void	bresenham(t_fdf *fdf, t_point *p1, t_point *p2);
void	bresenham_draw(t_bresenham *b);
void	bresenham_axis(t_bresenham *b);
void	bresenham_octantes(t_bresenham *b);
// } bresenham_line_algorithm

#endif