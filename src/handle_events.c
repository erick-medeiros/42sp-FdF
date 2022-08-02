/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/01 23:48:27 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		free_success_exit(fdf, 1);
	else if (keycode == KEY_DOT)
		fdf->camera.show_info *= -1;
	else if (keycode == KEY_L)
		fdf->camera.show_coord *= -1;
	else if (keycode == KEY_C)
		handle_keypress_color(fdf);
	else if (keycode == KEY_R)
		reset_camera(fdf);
	else if (keycode == KEY_O)
		fdf->camera.projection = TOP;
	else if (keycode == KEY_I)
		fdf->camera.projection = ISOMETRIC;
	else if (keycode == KEY_P)
		fdf->camera.projection = PERSPECTIVE;
	if (keycode == KEY_Z)
		fdf->camera.scale_z -= 10;
	else if (keycode == KEY_X)
		fdf->camera.scale_z += 10;
	else
		handle_keypress_transform(keycode, fdf);
	render(fdf);
	return (0);
}

void	handle_keypress_color(t_fdf *fdf)
{
	if (fdf->camera.color_palette == COLORPALETTE0)
		fdf->camera.color_palette = COLORPALETTE1;
	else if (fdf->camera.color_palette == COLORPALETTE1)
		fdf->camera.color_palette = COLORPALETTE2;
	else if (fdf->camera.color_palette == COLORPALETTE2)
		fdf->camera.color_palette = COLORPALETTE3;
	else if (fdf->camera.color_palette == COLORPALETTE3)
		fdf->camera.color_palette = COLORPALETTE0;
}

int	handle_keypress_transform(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_MINUS1 || keycode == KEY_MINUS2)
		fdf->camera.scale_factor -= 10;
	else if (keycode == KEY_PLUS1 || keycode == KEY_PLUS2)
		fdf->camera.scale_factor += 10;
	else if (keycode == KEY_RIGHT)
		fdf->camera.move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->camera.move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->camera.move_y += 10;
	else if (keycode == KEY_UP)
		fdf->camera.move_y -= 10;
	else if (keycode == KEY_A)
		fdf->camera.angle_z += (5 * ANG_1_RADIAN);
	else if (keycode == KEY_D)
		fdf->camera.angle_z -= (5 * ANG_1_RADIAN);
	else if (keycode == KEY_W)
		fdf->camera.angle_x += (5 * ANG_1_RADIAN);
	else if (keycode == KEY_S)
		fdf->camera.angle_x -= (5 * ANG_1_RADIAN);
	else if (keycode == KEY_Q)
		fdf->camera.angle_y -= (5 * ANG_1_RADIAN);
	else if (keycode == KEY_E)
		fdf->camera.angle_y += (5 * ANG_1_RADIAN);
	return (0);
}

int	handle_x11_destroy_notify(t_fdf *fdf)
{
	free_all(fdf);
	success_exit(1);
	return (0);
}

int	handle_expose(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
