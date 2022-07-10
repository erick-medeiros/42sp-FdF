/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:57:52 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/10 22:46:55 by eandre-f         ###   ########.fr       */
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
}	t_fdf;

int			render(t_fdf *fdf);
int			fdf_exit(t_fdf *fdf, int exit_status);
int			handle_keypress(int keycode, t_fdf *fdf);
int			handle_expose(t_fdf *fdf);
void		init_fdf(t_fdf *fdf);

#endif