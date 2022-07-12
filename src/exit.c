/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:34:13 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/12 03:05:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_error_exit(t_fdf *fdf, int error_status)
{
	free_all(fdf);
	error_exit(error_status);
}

void	error_exit(int error_status)
{
	if (error_status == 1)
		perror("Incorrect use");
	if (error_status == 2)
		perror("Cannot read file");
	if (error_status == 3)
		perror("Cannot open display");
	exit(1);
}

void	success_exit(int success_status)
{
	if (success_status == 1)
		ft_printf("FdF closed successfully!\n");
	exit(0);
}
