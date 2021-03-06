/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/15 16:52:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	char	*filepath;

	if (argc != 2)
	{
		ft_printf("execute ~ error_exit(1)\n");
		filepath = "maps/42.fdf";
	}
	else
	{
		filepath = argv[1];
	}
	init_fdf(&fdf);
	read_map(&fdf, filepath);
	render(&fdf);
	mlx_loop_hook(fdf.mlx_ptr, &render, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_expose_hook(fdf.win_ptr, &handle_expose, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
