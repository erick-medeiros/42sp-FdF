/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:54:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 00:39:14 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define TEXT_C	DEFAULT_COLOR
#define HIGHL_C	HIGHLIGHT_COLOR

static int	show_info_rotate(t_fdf *fdf, int w, int h)
{
	void	*mlx;
	void	*win;
	char	str[100];

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Rotate Z: press 'A' or 'D'");
	ft_sprintf(str, 100, "X (%ig) Y (%ig) Z (%ig)",
		(int)(fdf->camera.angle_x * (180 / M_PI)),
		(int)(fdf->camera.angle_y * (180 / M_PI)),
		(int)(fdf->camera.angle_z * (180 / M_PI)));
	mlx_string_put(mlx, win, w, h += 20, HIGHL_C, str);
	return (h);
}

static int	show_info_position(t_fdf *fdf, int w, int h)
{
	void	*mlx;
	void	*win;
	char	str[100];

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Move: press arrow keys");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Scale Z: press 'Z' or 'X'");
	ft_sprintf(str, 100, "Scale (%i%%) Scale Z (%i%%)",
		fdf->camera.scale_factor, fdf->camera.scale_z);
	mlx_string_put(mlx, win, w, h += 20, HIGHL_C, str);
	return (h);
}

static int	show_info_projection(t_fdf *fdf, int w, int h)
{
	void	*mlx;
	void	*win;
	char	str[100];

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Projection");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Isometric: press 'I'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Perspective: press 'P'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Top View: press 'O'");
	if (fdf->camera.projection == ISOMETRIC)
		ft_sprintf(str, 100, "Projection (Isometric)");
	else if (fdf->camera.projection == PERSPECTIVE)
		ft_sprintf(str, 100, "Projection (Perspective)");
	else
		ft_sprintf(str, 100, "Projection (Top)");
	mlx_string_put(mlx, win, w, h += 20, HIGHL_C, str);
	return (h);
}

static int	show_info_color(t_fdf *fdf, int w, int h)
{
	void	*mlx;
	void	*win;
	char	str[100];

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Color");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Palette: press 'C'");
	ft_sprintf(str, 100, "Palette Code (%i)", fdf->camera.color_palette);
	mlx_string_put(mlx, win, w, h += 20, HIGHL_C, str);
	return (h);
}

void	instructions(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;

	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	w = 30;
	h = 0;
	if (fdf->camera.show_info != 1)
		return ;
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Press 'ESC' to close");
	h = show_info_rotate(fdf, w, h);
	h = show_info_position(fdf, w, h);
	h = show_info_projection(fdf, w, h);
	h = show_info_color(fdf, w, h);
	mlx_string_put(mlx, win, w, h += 30, TEXT_C, "Info: press '.'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Axis XYZ: press 'L'");
	mlx_string_put(mlx, win, w, h += 20, TEXT_C, "Reset view: press 'R'");
}
