/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 01:21:40 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/27 20:58:24 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		increase_map(t_fdf *f)
{
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x *= SCALE_CHANGER;
		MAP[i].y *= SCALE_CHANGER;
		MAP[i].z *= SCALE_CHANGER;
	}
}

void		decrease_map(t_fdf *f)
{
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x /= SCALE_CHANGER;
		MAP[i].y /= SCALE_CHANGER;
		MAP[i].z /= SCALE_CHANGER;
	}
}

void		init_mlx(char **av, t_fdf *f)
{
	WLEN = MX.x * SCALE;
	WHEI = MX.y * SCALE;

	// if (WLEN < 10)
	// 	WLEN = 200;
	// if (WHEI < 10)
	// 	WHEI = 50;
	if ((f->mlx = mlx_init()) == NULL)
		put_error(3);
	if ((f->win =
	mlx_new_window(f->mlx, WLEN, WHEI, av[1])) == NULL)
		put_error(4);
	if ((f->img =
	mlx_new_image(f->mlx, WLEN, WHEI)) == NULL)
		put_error(8);
	if ((f->dim = (int*)
	mlx_get_data_addr(f->img, &f->bpp, &f->line_size, &f->endian)) == NULL)
		put_error(9);
}

void		deinit_mlx(t_fdf *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
}
