/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:33:27 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/30 03:13:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void					put_center(t_fdf *f)
{
	const int	s2 = SCALE / 2;
	const int	s4 = SCALE / 4;
	const int	const_x = MX.x / 2 * s2 + MX.x * s4;
	const int	const_y = MX.y / 2 * s2 + MX.y * s4;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].c.x = MAP[i].temp.x * s2 + const_x;
		MAP[i].c.y = MAP[i].temp.y * s2 + const_y;
	}
}

void					rotation_z(t_fdf *f, accuracy_mod z)
{
	const accuracy_mod		rad = (z * M_PI) / 180;
	const accuracy_mod		cosinus = cos(rad);
	const accuracy_mod		sinus = sin(rad);
	t_angle					a;
	int						i;

	ANGLE.z += z;
	i = -1;
	while (++i < VOLUME)
	{
		a.x = MAP[i].orig.x;
		a.y = MAP[i].orig.y;
		MAP[i].temp.x = a.x * cosinus - a.y * sinus;
		MAP[i].temp.y = a.x * sinus + a.y * cosinus;
	}
	put_center(f);
}

void					rotation_y(t_fdf *f, accuracy_mod y)
{
	const accuracy_mod		rad = (y * M_PI) / 180;
	const accuracy_mod		cosinus = cos(rad);
	const accuracy_mod		sinus = sin(rad);
	t_angle					a;
	int						i;

	ANGLE.y += y;
	i = -1;
	while (++i < VOLUME)
	{
		a.x = MAP[i].orig.x;
		a.z = MAP[i].orig.z;
		MAP[i].temp.x = a.x * cosinus + a.z * sinus;
		MAP[i].temp.z = a.z * cosinus - a.x * sinus;
	}
	put_center(f);
}

void					rotation_x(t_fdf *f, accuracy_mod x)
{
	const accuracy_mod		rad = (x * M_PI) / 180;
	const accuracy_mod		cosinus = cos(rad);
	const accuracy_mod		sinus = sin(rad);
	t_angle					a;
	int						i;

	ANGLE.x += x;
	i = -1;
	while (++i < VOLUME)
	{
		a.y = MAP[i].orig.y;
		a.z = MAP[i].orig.z;
		MAP[i].temp.y = a.y * cosinus - a.z * sinus;
		MAP[i].temp.z = a.y * sinus + a.z * cosinus;
	}
	put_center(f);
}


inline void				prepare_map(t_fdf *f)
{
	ft_bzero(&ANGLE, sizeof(t_angle));
	rotation_x(f, 50);
	rotation_y(f, 10);
}
