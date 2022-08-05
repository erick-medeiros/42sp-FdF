/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:15:30 by eandre-f          #+#    #+#             */
/*   Updated: 2022/08/05 16:05:51 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// Cohen–Sutherland clipping algorithm

#define CLIP_LEFT 	0b00000001
#define CLIP_RIGHT 	0b00000010
#define CLIP_BOTTOM 0b00000100
#define CLIP_TOP		0b00001000
#define XMIN				0
#define XMAX				WINDOW_WIDTH
#define YMIN				0
#define YMAX				WINDOW_HEIGHT

static int	compute_outcode(float x, float y)
{
	int	code;

	code = 0;
	if (x < XMIN)
		code |= CLIP_LEFT;
	else if (x > XMAX)
		code |= CLIP_RIGHT;
	if (y < YMIN)
		code |= CLIP_BOTTOM;
	else if (y > YMAX)
		code |= CLIP_TOP;
	return (code);
}

static void	position_update(t_line *line, t_point *point, int outcode_out)
{
	float	delta_x;
	float	delta_y;

	delta_x = line->p2.x - line->p1.x;
	delta_y = line->p2.y - line->p1.y;
	if (outcode_out & CLIP_TOP)
	{
		point->x = line->p1.x + (delta_x) * (YMAX - line->p1.y) / (delta_y);
		point->y = YMAX;
	}
	else if (outcode_out & CLIP_BOTTOM)
	{
		point->x = line->p1.x + (delta_x) * (YMIN - line->p1.y) / (delta_y);
		point->y = YMIN;
	}
	else if (outcode_out & CLIP_RIGHT)
	{
		point->y = line->p1.y + (delta_y) * (XMAX - line->p1.x) / (delta_x);
		point->x = XMAX;
	}
	else if (outcode_out & CLIP_LEFT)
	{
		point->y = line->p1.y + (delta_y) * (XMIN - line->p1.x) / (delta_x);
		point->x = XMIN;
	}
}

static void	update_xy(t_point *dest, t_point *origin)
{
	dest->x = origin->x;
	dest->y = origin->y;
}

void	cohensutherland_clipping(t_line *line)
{
	int		outcode0;
	int		outcode1;
	int		outcode_out;
	t_point	point;

	line->show = -1;
	while (line->show == -1)
	{
		outcode0 = compute_outcode(line->p1.x, line->p1.y);
		outcode1 = compute_outcode(line->p2.x, line->p2.y);
		if (!(outcode0 | outcode1))
			line->show = 1;
		else if (outcode0 & outcode1)
			line->show = 0;
		else
		{
			outcode_out = fmax(outcode0, outcode1);
			position_update(line, &point, outcode_out);
			if (outcode_out == outcode0)
				update_xy(&line->p1, &point);
			else
				update_xy(&line->p2, &point);
		}
	}
}

void	camera_clipping(t_line *line, double *z1_distance, double *z2_distance)
{
	double	near_camera;
	double	n;

	near_camera = -0.1;
	if (*z1_distance <= near_camera && *z2_distance <= near_camera)
		line->show = 1;
	else if (*z1_distance > near_camera && *z2_distance > near_camera)
		line->show = 0;
	else if (*z1_distance <= near_camera && *z2_distance > near_camera)
	{
		n = (*z1_distance - near_camera) / (*z1_distance - *z2_distance);
		line->p2.x = (n * line->p1.x) + ((1 - n) * line->p2.x);
		line->p2.y = (n * line->p1.y) + ((1 - n) * line->p2.y);
		line->p2.z = (n * line->p1.z) + ((1 - n) * line->p2.z);
		*z2_distance = near_camera;
	}
	else if (*z1_distance > near_camera && *z2_distance <= near_camera)
	{
		n = (*z2_distance - near_camera) / (*z2_distance - *z1_distance);
		line->p1.x = (n * line->p2.x) + ((1 - n) * line->p1.x);
		line->p1.y = (n * line->p2.y) + ((1 - n) * line->p1.y);
		line->p1.z = (n * line->p2.z) + ((1 - n) * line->p1.z);
		*z1_distance = near_camera;
	}
}
