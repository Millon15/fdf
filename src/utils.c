/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 01:21:40 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/23 17:08:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		increace_map(t_fdf *f)
{
	const int	s2 = SCALE / 2;
	const int	s4 = SCALE / 4;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x *= SCALE_CHANGER;
		MAP[i].y *= SCALE_CHANGER;
	}
}

void		decreace_map(t_fdf *f)
{
	const int	s2 = SCALE / 2;
	const int	s4 = SCALE / 4;
	int			i;

	i = -1;
	while (++i < VOLUME)
	{
		MAP[i].x /= SCALE_CHANGER;
		MAP[i].y /= SCALE_CHANGER;
	}
}

void		init_mlx(char **av, t_fdf *f)
{
	const int	x = IMG_MAX_X;
	const int	y = IMG_MAX_Y;

	if ((f->mlx = mlx_init()) == NULL)
		put_error(3);
	if ((f->win = mlx_new_window(f->mlx, x, y, av[1])) == NULL)
		put_error(4);
	if ((f->img = mlx_new_image(f->mlx, x, y)) == NULL)
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
