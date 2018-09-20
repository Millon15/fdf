/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 06:39:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/20 13:20:36 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static inline int	put_center(int i, int j)
{
	return (i * SCALE / 2 + j * SCALE / 4);
}

static inline void	bond_two_pixels(t_coo p[2], t_fdf *f)
{
	int			x;
	int			y;

	x = p[0].x;
	y = p[0].y;
	if (p[0].x <= p[1].x && p[0].y <= p[1].y)
		while (x <= p[1].x || y <= p[1].y)
			mlx_pixel_put(f->mlx, f->win,
			(x <= p[1].x) ? x++ : x,
			(y <= p[1].y) ? y++ : y, 0xffffff);
	else if (p[0].x >= p[1].x && p[0].y <= p[1].y)
		while (x >= p[1].x || y <= p[1].y)
			mlx_pixel_put(f->mlx, f->win,
			(x >= p[1].x) ? x-- : x,
			(y <= p[1].y) ? y++ : y, 0xffffff);
	else if (p[0].x <= p[1].x && p[0].y >= p[1].y)
		while (x <= p[1].x || y >= p[1].y)
			mlx_pixel_put(f->mlx, f->win,
			(x <= p[1].x) ? x++ : x,
			(y >= p[1].y) ? y-- : y, 0xffffff);
	else if (p[0].x >= p[1].x && p[0].y >= p[1].y)
		while (x >= p[1].x || y >= p[1].y)
			mlx_pixel_put(f->mlx, f->win,
			(x >= p[1].x) ? x-- : x,
			(y >= p[1].y) ? y-- : y, 0xffffff);
}

inline void			put_map(t_fdf *f)
{
	t_coo		p[2];
	int			x;
	int			y;

	y = -1;
	while (++y <= f->max.y)
	{
		x = -1;
		p[0].y = put_center(y, f->max.y);
		while (++x <= f->max.x)
		{
			p[0].x = put_center(x, f->max.x);
			p[1].x = p[0].x;
			p[1].y = put_center(y + 1, f->max.y);
			(y + 1 <= f->max.y) ? bond_two_pixels(p, f) : 0;
			p[1].x = put_center(x + 1, f->max.x);
			p[1].y = put_center(y, f->max.y);
			(x + 1 <= f->max.x) ? bond_two_pixels(p, f) : 0;
		}
	}
}
