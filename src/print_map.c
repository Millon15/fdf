/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 06:39:02 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/25 21:56:09 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static inline void		put_pixel_on_image(t_fdf *f, int x, int y)
{
	f->dim[y * f->line_size / sizeof(int) + x] =
	mlx_get_color_value(f->mlx, 0xffffff);
}

static inline void		put_pixels_x(t_coo p[2], t_fdf *f,
	const t_coo *d, const int iter[2])
{
	int				di;
	int				x;
	int				y;
	int				i;
	const t_coo		s = {

	(p[1].x >= p[0].x) ? 1 : -1, (p[1].y >= p[0].y) ? 1 : -1};
	di = (d->y << 1) - d->x;
	x = p[0].x + s.x;
	y = p[0].y;
	i = 1;
	put_pixel_on_image(f, p[0].x, p[0].y);
	while (i <= d->x)
	{
		if (di > 0)
		{
			di += iter[1];
			y += s.y;
		}
		else
			di += iter[0];
		put_pixel_on_image(f, x, y);
		x += s.x;
		i++;
	}
}

static inline void		put_pixels_y(t_coo p[2], t_fdf *f,
	const t_coo *d, const int iter[2])
{
	int				di;
	int				x;
	int				y;
	int				i;
	const t_coo		s = {

	(p[1].x >= p[0].x) ? 1 : -1, (p[1].y >= p[0].y) ? 1 : -1};
	di = (d->x << 1) - d->y;
	y = p[0].y + s.y;
	x = p[0].x;
	i = 1;
	put_pixel_on_image(f, p[0].x, p[0].y);
	while (i <= d->y)
	{
		if (di > 0)
		{
			di += iter[1];
			x += s.x;
		}
		else
			di += iter[0];
		put_pixel_on_image(f, x, y);
		y += s.y;
		i++;
	}
}

static inline void		bond_two_pixels(t_coo p[2], t_fdf *f)
{
	const t_coo		d = {ft_abs(p[1].x - p[0].x), ft_abs(p[1].y - p[0].y)};
	const int		iter[2] = {
		((d.y <= d.x) ? d.y : d.x) << 1,
		((d.y <= d.x) ? d.y - d.x : d.x - d.y) << 1};

	if (d.y <= d.x)
		put_pixels_x(p, f, &d, iter);
	else
		put_pixels_y(p, f, &d, iter);
}

inline void				put_map(t_fdf *f)
{
	int				line_down;
	t_coo			p[2];
	int				i;

	ft_bzero(f->dim, IMG_MAX_Y * IMG_MAX_X * sizeof(int));
	mlx_clear_window(f->mlx, f->win);
	i = -1;
	while (++i < VOLUME)
	{
		p[0].x = MAP[i].x;
		p[0].y = MAP[i].y;
		if ((i + 1) < VOLUME
		&& (p[1].x = MAP[i + 1].x) | 1
		&& (p[1].y = MAP[i].y) | 1)
			bond_two_pixels(p, f);
		if ((line_down = i + MX.x) < VOLUME
		&& (p[1].x = MAP[line_down].x) | 1
		&& (p[1].y = MAP[line_down].y) | 1)
			bond_two_pixels(p, f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
