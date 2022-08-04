/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/03 22:39:29 by eandre-f         ###   ########.fr       */
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

void	transform_scale(t_line *line, int scale_factor)
{
	line->p1.x *= scale_factor;
	line->p2.x *= scale_factor;
	line->p1.y *= scale_factor;
	line->p2.y *= scale_factor;
}

void	transform_scale_z(t_line *line, int scale_z)
{
	float	scale;

	scale = (float) scale_z / 100;
	line->p1.z *= scale;
	line->p2.z *= scale;
}
