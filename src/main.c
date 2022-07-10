/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/10 22:32:19 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//read_map("maps/42.fdf");

int	main(void)
{
	t_fdf	fdf;

	init_fdf(&fdf);
	fdf.mlx_ptr = mlx_init();
	if (fdf.mlx_ptr == NULL)
		return (fdf_exit(&fdf, EXIT_FAILURE));
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	if (fdf.win_ptr == NULL)
		return (fdf_exit(&fdf, EXIT_FAILURE));
	fdf.img.img_ptr = mlx_new_image(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf.img.img_ptr == NULL)
		return (fdf_exit(&fdf, EXIT_FAILURE));
	fdf.img.data = mlx_get_data_addr(fdf.img.img_ptr, &fdf.img.bpp,
			&fdf.img.size_line, &fdf.img.endian);
	render(&fdf);
	mlx_loop_hook(fdf.mlx_ptr, &render, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_expose_hook(fdf.win_ptr, &handle_expose, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (fdf_exit(&fdf, EXIT_SUCCESS));
}
