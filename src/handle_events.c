/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/30 16:28:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		free_success_exit(fdf, 1);
	else if (keycode == KEY_DOT)
		fdf->camera.show_info *= -1;
	else if (keycode == KEY_C)
		fdf->camera.show_coord *= -1;
	else if (keycode == KEY_R)
		reset_camera(fdf);
	else if (keycode == KEY_O)
		fdf->camera.projection = TOP;
	else if (keycode == KEY_I)
		fdf->camera.projection = ISOMETRIC;
	else if (keycode == KEY_P)
		fdf->camera.projection = PERSPECTIVE;
	else
		handle_keypress_transform(keycode, fdf);
	return (0);
}

int	handle_keypress_transform(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS1 || keycode == KEY_PLUS2)
		fdf->camera.scale_factor += 1;
	else if (keycode == KEY_MINUS1 || keycode == KEY_MINUS2)
		fdf->camera.scale_factor -= 1;
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
		fdf->camera.angle_y += (5 * ANG_1_RADIAN);
	else if (keycode == KEY_E)
		fdf->camera.angle_y -= (5 * ANG_1_RADIAN);
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
