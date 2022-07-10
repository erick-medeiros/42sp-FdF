/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/10 23:12:07 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//read_map("maps/42.fdf");

int	main(void)
{
	t_fdf	fdf;

	init_fdf(&fdf);
	render(&fdf);
	mlx_loop_hook(fdf.mlx_ptr, &render, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_expose_hook(fdf.win_ptr, &handle_expose, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
