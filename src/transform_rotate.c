/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 16:09:26 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_rotate_x(t_point *point, double angle)
{
	int	y;
	int	z;

	y = point->y * cos(angle) - point->z * sin(angle);
	z = point->y * sin(angle) + point->z * cos(angle);
	point->y = y;
	point->z = z;
}

void	transform_rotate_y(t_point *point, double angle)
{
	int	x;
	int	z;

	x = point->x * cos(angle) + point->z * sin(angle);
	z = -point->x * sin(angle) + point->z * cos(angle);
	point->x = x;
	point->z = z;
}

void	transform_rotate_z(t_point *point, double angle)
{
	int	x;
	int	y;

	x = point->x * cos(angle) - point->y * sin(angle);
	y = point->x * sin(angle) + point->y * cos(angle);
	point->x = x;
	point->y = y;
}

void	transform_rotate(t_camera *camera, t_point *point)
{
	transform_rotate_x(point, camera->alpha);
	transform_rotate_y(point, camera->beta);
	transform_rotate_z(point, camera->gamma);
}
