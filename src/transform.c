/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/02 16:58:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_translate(t_line *line, t_camera *camera)
{
	line->p1.x += camera->move_x;
	line->p2.x += camera->move_x;
	line->p1.y += camera->move_y;
	line->p2.y += camera->move_y;
}

void	transform_scale(t_line *line, float scale_factor)
{
	line->p1.x = (int)(line->p1.x * scale_factor);
	line->p2.x = (int)(line->p2.x * scale_factor);
	line->p1.y = (int)(line->p1.y * scale_factor);
	line->p2.y = (int)(line->p2.y * scale_factor);
}

void	transform_scale_z(t_line *line, t_camera *camera)
{
	float	z1;
	float	z2;
	float	scale_z;

	scale_z = (float) camera->scale_z / 100;
	z1 = line->p1.z * scale_z;
	z2 = line->p2.z * scale_z;
	line->p1.z = (int)z1;
	line->p2.z = (int)z2;
}
