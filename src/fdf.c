/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/18 23:15:00 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static inline void	put_error(int errnum)
{
	ft_putnbr(errnum);
	exit(0);
}

int					main(int ac, char **av)
{
	t_fdf	f;

	// if (ac <= 1)
	// 	put_error(1);
	if ((f.mlx = mlx_init()) == NULL)
		put_error(2);
	if ((f.win = mlx_new_window(f.mlx, IX, IY, "some window")) == NULL)
		put_error(3);
	mlx_string_put(f.mlx, f.win, 5, 5, 0xffffff, "Hello world!");
	mlx_loop(f.mlx);
	mlx_destroy_window(f.mlx, f.win);
	return (0);
}
