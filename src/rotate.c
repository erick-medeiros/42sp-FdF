/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/24 01:55:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rotate_x(t_vector *vector, double angle)
{
	int y;
	int z;

	y = vector->y1 * cos(angle) - vector->z1 * sin(angle);
	z = vector->y1 * sin(angle) + vector->z1 * cos(angle);
	vector->y1 = y;
	vector->z1 = z;
	y = vector->y2 * cos(angle) - vector->z2 * sin(angle);
	z = vector->y2 * sin(angle) + vector->z2 * cos(angle);
	vector->y2 = y;
	vector->z2 = z;
}

void	rotate_y(t_vector *vector, double angle)
{
	int x;
	int z;

	x = vector->x1 * cos(angle) + vector->z1 * sin(angle);
	z = -vector->x1 * sin(angle) + vector->z1 * cos(angle);
	vector->x1 = x;
	vector->z1 = z;
	x = vector->x2 * cos(angle) + vector->z2 * sin(angle);
	z = -vector->x2 * sin(angle) + vector->z2 * cos(angle);
	vector->x2 = x;
	vector->z2 = z;
}

void	rotate_z(t_vector *vector, double angle)
{
	int x;
	int y;

	x = vector->x1 * cos(angle) - vector->y1 * sin(angle);
	y = vector->x1 * sin(angle) + vector->y1 * cos(angle);
	vector->x1 = x;
	vector->y1 = y;
	x = vector->x2 * cos(angle) - vector->y2 * sin(angle);
	y = vector->x2 * sin(angle) + vector->y2 * cos(angle);
	vector->x2 = x;
	vector->y2 = y;
}

void	rotate(t_view *view, t_vector *vector)
{
	rotate_x(vector, view->alpha);
	rotate_y(vector, view->beta);
	rotate_z(vector, view->gamma);
}
