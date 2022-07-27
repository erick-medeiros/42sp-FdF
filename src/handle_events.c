/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/27 23:04:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		free_success_exit(fdf, 1);
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
