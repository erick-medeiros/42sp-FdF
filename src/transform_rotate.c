/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:59 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 19:39:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_rotate_x(t_line *line, double angle)
{
	int	y;
	int	z;

	y = line->p1.y;
	z = line->p1.z;
	line->p1.y = y * cos(angle) - z * sin(angle);
	line->p1.z = y * sin(angle) + z * cos(angle);
	y = line->p2.y;
	z = line->p2.z;
	line->p2.y = y * cos(angle) - z * sin(angle);
	line->p2.z = y * sin(angle) + z * cos(angle);
}

void	transform_rotate_y(t_line *line, double angle)
{
	int	x;
	int	z;

	x = line->p1.x;
	z = line->p1.z;
	line->p1.x = x * cos(angle) + z * sin(angle);
	line->p1.z = -x * sin(angle) + z * cos(angle);
	x = line->p2.x;
	z = line->p2.z;
	line->p2.x = x * cos(angle) + z * sin(angle);
	line->p2.z = -x * sin(angle) + z * cos(angle);
}

void	transform_rotate_z(t_line *line, double angle)
{
	int	x;
	int	y;

	x = line->p1.x;
	y = line->p1.y;
	line->p1.x = x * cos(angle) - y * sin(angle);
	line->p1.y = x * sin(angle) + y * cos(angle);
	x = line->p2.x;
	y = line->p2.y;
	line->p2.x = x * cos(angle) - y * sin(angle);
	line->p2.y = x * sin(angle) + y * cos(angle);
}

void	transform_rotate(t_line *line, t_camera *camera)
{
	transform_rotate_x(line, camera->alpha);
	transform_rotate_y(line, camera->beta);
	transform_rotate_z(line, camera->gamma);
}
