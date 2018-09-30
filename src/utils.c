/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 01:21:40 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/30 02:50:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		increase_map(t_fdf *f)
{
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].temp.x *= SCALE_CHANGER;
		MAP[i].temp.y *= SCALE_CHANGER;
		MAP[i].temp.z *= SCALE_CHANGER;
	}
	put_center(f);
}

void		decrease_map(t_fdf *f)
{
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].temp.x /= SCALE_CHANGER;
		MAP[i].temp.y /= SCALE_CHANGER;
		MAP[i].temp.z /= SCALE_CHANGER;
	}
	put_center(f);
}

void		init_mlx(char **av, t_fdf *f)
{
	WLEN = MX.x * SCALE;
	WHEI = MX.y * SCALE;
	WSIZE = WLEN * WHEI;
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
	exit(0);
}
