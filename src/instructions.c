/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:54:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/30 12:45:20 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	show_info_rotate(t_fdf *fdf, int w, int h)
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
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, w, h += 20, C_WHITE, str);
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
	mlx_string_put(mlx, win, w, h += 20, C_WHITE, "Press '.' to hidden info");
	mlx_string_put(mlx, win, w, h += 20, C_WHITE,
		"Press 'C' to show axis XYZ");
	show_info_rotate(fdf, w, h);
}
