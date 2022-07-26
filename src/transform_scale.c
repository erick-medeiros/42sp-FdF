/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:16 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 01:59:09 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_scale_x(t_point *point, int scale_factor)
{
	point->x = point->x * scale_factor;
}

void	transform_scale_y(t_point *point, int scale_factor)
{
	point->y = point->y * scale_factor;
}

void	transform_scale_z(t_point *point, int scale_factor)
{
	point->z = point->z * scale_factor;
}

void	transform_scale(t_point *point, int scale_factor)
{
	transform_scale_x(point, scale_factor);
	transform_scale_y(point, scale_factor);
}
