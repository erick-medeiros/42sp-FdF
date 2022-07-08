/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:55:08 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/08 23:47:17 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		fd;
	char	*string;

	fd = open("./Makefile", O_RDWR);
	string = get_next_line(fd);
	ft_printf("%s", string);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	mlx_loop(mlx);
}
