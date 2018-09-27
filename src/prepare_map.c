/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:33:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/28 01:19:54 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void					put_center(t_fdf *f)
{
	const int	s2 = SCALE / 2;
	const int	s4 = SCALE / 4;
	const int	const_x = MX.x / 2 * s2 + MX.x * s4;
	const int	const_y = MX.y / 2 * s2 + MX.y * s4;
	const int	win2 = f->line_size / 2;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x = MAP[i].x_back * s2 + const_x;
		MAP[i].y = MAP[i].y_back * s2 + const_y;
		// MAP[i].x = MAP[i].x_back + win2;
		// MAP[i].y = MAP[i].y_back + win2;
	}
}

void					rotation_z(t_fdf *f, float z)
{
	long double		rad;
	long double		x;
	long double		y;
	int				i;

	ANGLE.z += z;
	rad = (ANGLE.z * M_PI) / 180;
	i = -1;
	while (++i < VOLUME)
	{
		x = MAP[i].x_orig;
		y = MAP[i].y_orig;
		MAP[i].x_back = x * cos(rad) - y * sin(rad);
		MAP[i].y_back = x * sin(rad) + y * cos(rad);
	}
	put_center(f);
}

void					rotation_y(t_fdf *f, float y)
{
	long double		rad;
	long double		x;
	long double		z;
	int				i;

	ANGLE.y += y;
	rad = (ANGLE.y * M_PI) / 180;
	i = -1;
	while (++i < VOLUME)
	{
		x = MAP[i].x_orig;
		z = MAP[i].z_orig;
		MAP[i].z_back = z * cos(rad) + x * sin(rad);
		MAP[i].x_back = z * sin(rad) + x * cos(rad);
	}
	put_center(f);
}

void					rotation_x(t_fdf *f, float x)
{
	long double		rad;
	long double		y;
	long double		z;
	int				i;

	ANGLE.x += x;
	rad = (ANGLE.x * M_PI) / 180;
	i = -1;
	while (++i < VOLUME)
	{
		y = MAP[i].y_orig;
		z = MAP[i].z_orig;
		MAP[i].y_back = y * cos(rad) - z * sin(rad);
		MAP[i].z_back = y * sin(rad) + z * cos(rad);
	}
	put_center(f);
}

inline void				prepare_map(t_fdf *f)
{
	ft_bzero(&ANGLE, sizeof(t_angle));
	rotation_x(f, 50);
	rotation_y(f, 10);
}
