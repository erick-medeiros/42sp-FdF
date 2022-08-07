/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:34:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/07 14:56:44 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error_exit(int error_status)
{
	if (error_status == 1)
		ft_printf("Incorrect use\n");
	if (error_status == 2)
		ft_printf("Cannot read file\n");
	if (error_status == 3)
		ft_printf("Cannot open display\n");
	if (error_status == 4)
		ft_printf("Wrongly written file\n");
	if (error_status == 5)
		ft_printf("Map creation error\n");
	perror("System");
	exit(1);
}

void	success_exit(int success_status)
{
	if (success_status == 1)
		ft_printf("FdF closed successfully!\n");
	exit(0);
}

void	free_error_exit(t_fdf *fdf, int error_status)
{
	free_all(fdf);
	error_exit(error_status);
}

void	free_filedata_error_exit(char ***filedata, int error_status)
{
	free_filedata(filedata);
	error_exit(error_status);
}

void	free_map_error_exit(t_map *map, int error_status)
{
	free_coordinates(map);
	error_exit(error_status);
}
