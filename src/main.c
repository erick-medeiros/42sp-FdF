/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 14:40:30 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		error_exit(1);
	read_map(&fdf.map, argv[1]);
	init_fdf(&fdf);
	render(&fdf);
	mlx_hook(fdf.win_ptr, 17, 0, &handle_exit, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_expose_hook(fdf.win_ptr, &handle_expose, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
