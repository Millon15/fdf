/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:33:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/25 20:51:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void					put_center(t_fdf *f)
{
	const int	s2 = SCALE / 2;
	const int	s4 = SCALE / 4;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x = MAP[i].x_bak * s2 + MX.x * s4;
		MAP[i].y = MAP[i].y_bak * s2 + MX.y * s4;
		// MAP[i].x = MAP[i].x_bak * SCALE;
		// MAP[i].y = MAP[i].y_bak * SCALE;
		MAP[i].z = MAP[i].z_bak * s4;
	}
}

static inline void		prepare_to_rotation(t_fdf *f)
{
	const int	center = VOLUME / 2;
	const int	ls = f->line_size / 2;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x = MAP[i].x - ls;
		MAP[i].y = MAP[i].y_bak * SCALE;
		MAP[i].z = MAP[i].z_bak * SCALE;
	}
}

void					rotation_z(t_fdf *f, long double z)
{
	int				i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x =
		MAP[i].x * cos((z * M_PI) / 180) - MAP[i].y * sin((z * M_PI) / 180);
		MAP[i].y =
		MAP[i].x * sin((z * M_PI) / 180) + MAP[i].y * cos((z * M_PI) / 180);
	}
}

void					rotation_y(t_fdf *f, long double y)
{
	int				i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].z =
		MAP[i].z * cos((y * M_PI) / 180) - MAP[i].x * sin((y * M_PI) / 180);
		MAP[i].x =
		MAP[i].z * sin((y * M_PI) / 180) + MAP[i].x * cos((y * M_PI) / 180);
	}
}

void					rotation_x(t_fdf *f, long double x)
{
	int				i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].y =
		MAP[i].y * cos((x * M_PI) / 180) - MAP[i].z * sin((x * M_PI) / 180);
		MAP[i].z =
		MAP[i].y * sin((x * M_PI) / 180) + MAP[i].z * cos((x * M_PI) / 180);
	}
}

inline void				prepare_map(t_fdf *f)
{
	put_center(f);
}
