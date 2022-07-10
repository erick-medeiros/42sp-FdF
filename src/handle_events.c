/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:11 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/10 18:54:18 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define KEY_ESC	65307

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Pressed esc\n");
		fdf_exit(fdf, EXIT_SUCCESS);
	}
	return (0);
}

int	handle_expose(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
