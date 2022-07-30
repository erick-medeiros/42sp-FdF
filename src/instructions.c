/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:54:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/30 14:57:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	show_info_rotate(t_fdf *fdf, int w, int h)
{
	char	str[100];

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 50, C_WHITE,
		"Rotate X: press 'S' or 'W'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Rotate Y: press 'Q' or 'E'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Rotate Z: press 'A' or 'D'");
	ft_sprintf(str, 100, "X (%ig) Y (%ig) Z (%ig)",
		(int)(fdf->camera.angle_x * (180 / M_PI)),
		(int)(fdf->camera.angle_y * (180 / M_PI)),
		(int)(fdf->camera.angle_z * (180 / M_PI)));
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_YELLOW, str);
	return (h);
}

static int	show_info_position(t_fdf *fdf, int w, int h)
{
	char	str[100];

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 50, C_WHITE,
		"Move: press arrow keys");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Zoom: press '-' or '+'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Scale Z: press 'Z' or 'X'");
	ft_sprintf(str, 100, "Scale (%i%%) Scale Z (%i%%)",
		fdf->camera.scale_factor, fdf->camera.scale_z);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_YELLOW, str);
	return (h);
}

static int	show_info_projection(t_fdf *fdf, int w, int h)
{
	char	str[100];

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 50, C_WHITE,
		"Projection");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Isometric: press 'I'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Perspective: press 'P'");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE,
		"Top View: press 'O'");
	if (fdf->camera.projection == ISOMETRIC)
		ft_sprintf(str, 100, "Projection (Isometric)");
	else if (fdf->camera.projection == PERSPECTIVE)
		ft_sprintf(str, 100, "Projection (Perspective)");
	else
		ft_sprintf(str, 100, "Projection (Top)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_YELLOW, str);
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
	w = 50;
	h = 0;
	if (fdf->camera.show_info != 1)
		return ;
	mlx_string_put(mlx, win, w, h += 50, C_WHITE, "Press 'ESC' to close");
	h = show_info_rotate(fdf, w, h);
	h = show_info_position(fdf, w, h);
	h = show_info_projection(fdf, w, h);
	mlx_string_put(mlx, win, w, h += 50, C_WHITE, "Info: press '.'");
	mlx_string_put(mlx, win, w, h += 20, C_WHITE, "Axis XYZ: press 'C'");
	mlx_string_put(mlx, win, w, h += 20, C_WHITE, "Reset view: press 'R'");
}
