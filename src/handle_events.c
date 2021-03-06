/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/12 03:06:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define KEY_ESC	65307

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		free_all(fdf);
		success_exit(1);
	}
	return (0);
}

int	handle_expose(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
