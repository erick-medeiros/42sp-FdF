/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 19:43:39 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_scale_x(t_line *line, int scale_factor)
{
	line->p1.x *= scale_factor;
	line->p2.x *= scale_factor;
}

void	transform_scale_y(t_line *line, int scale_factor)
{
	line->p1.y *= scale_factor;
	line->p2.y *= scale_factor;
}

void	transform_scale_z(t_line *line, int scale_factor)
{
	line->p1.z *= scale_factor;
	line->p2.z *= scale_factor;
}

void	transform_scale(t_line *line, int scale_factor)
{
	transform_scale_x(line, scale_factor);
	transform_scale_y(line, scale_factor);
}
