/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:21:21 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 03:26:27 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_translate_x(t_point *point, int motion_factor)
{
	point->x += motion_factor;
}

void	transform_translate_y(t_point *point, int motion_factor)
{
	point->y += motion_factor;
}

void	transform_translate_z(t_point *point, int motion_factor)
{
	point->z += motion_factor;
}
