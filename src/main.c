/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 16:49:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	check_arg(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	check_arg(argc, argv);
	read_map(&fdf.map, argv[1]);
	init_fdf(&fdf);
	render(&fdf);
	mlx_hook(fdf.win_ptr, 17, 0, &handle_exit, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_expose_hook(fdf.win_ptr, &handle_expose, &fdf);
	mlx_loop(fdf.mlx_ptr);
}

static void	check_arg(int argc, char **argv)
{
	char	*argument;
	char	*extension;

	if (argc != 2)
		error_exit(1);
	argument = ft_strrchr(argv[1], '.');
	if (argument == NULL)
		error_exit(6);
	extension = ft_strdup(".fdf");
	if (ft_strncmp(argument, extension, 5) != 0)
	{
		free(extension);
		error_exit(6);
	}
	free(extension);
}
