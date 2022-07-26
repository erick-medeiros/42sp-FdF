/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:21:21 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/26 19:51:06 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	transform_translate_x(t_line *line, int motion_factor)
{
	line->p1.x += motion_factor;
	line->p2.x += motion_factor;
}

void	transform_translate_y(t_line *line, int motion_factor)
{
	line->p1.y += motion_factor;
	line->p2.y += motion_factor;
}

void	transform_translate_z(t_line *line, int motion_factor)
{
	line->p1.z += motion_factor;
	line->p2.z += motion_factor;
}
