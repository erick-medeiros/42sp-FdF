/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/11 21:56:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		1120
# define WINDOW_HEIGHT		630

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

void		fdf_exit(t_fdf *fdf, int exit_status);
void		fdf_exit_error(t_fdf *fdf, int error_status);
void		free_filedata(char ***filedata);
void		*free_coordinates(t_fdf_map	*map);
void		init_fdf(t_fdf *fdf);
void		read_map(t_fdf *fdf, char *pathname);
int			render(t_fdf *fdf);
int			handle_keypress(int keycode, t_fdf *fdf);
int			handle_expose(t_fdf *fdf);

#endif