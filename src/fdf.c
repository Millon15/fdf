/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/27 17:32:20 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				put_error(int errnum)
{
	const char		usage[] = "./fdf <map_name>";

	(errnum == 1) ? ft_dprintf(2, "%s\n", usage) : false;
	(errnum == 2) ? perror("open failed") : false;
	(errnum == 3) ? ft_dprintf(2, "mlx_init failed\n") : false;
	(errnum == 4) ? ft_dprintf(2, "mlx_new_window failed\n") : false;
	(errnum == 5) ? ft_dprintf(2, "get_next_line failed\n") : false;
	(errnum == 6) ? perror("malloc failed") : false;
	if (errnum == 7)
		ft_dprintf(2, "wrong number of ints in string in map\n");
	(errnum == 8) ? ft_dprintf(2, "mlx_new_image failed\n") : false;
	(errnum == 9) ? ft_dprintf(2, "mlx_get_data_addr failed\n") : false;
	(errnum == 10) ? perror("close failed") : false;
	exit(1);
}

static inline int	key_handle(int key, t_fdf *f)
{
	if (key == ESC || key == Q)
		exit(0);
	else if (key == PLUS || key == PLUS1)
		increase_map(f);
	else if (key == MINUS || key == MINUS1)
		decrease_map(f);
	else if (key == LEFT || key == LEFT1 || key == LEFT2)
		rotation_y(f, 10);
	else if (key == RIGHT || key == RIGHT1 || key == RIGHT2)
		rotation_y(f, -10);
	else if (key == UP || key == UP1 || key == UP2)
		rotation_x(f, 10);
	else if (key == DOWN || key == DOWN1 || key == DOWN2)
		rotation_x(f, -10);
	else if (key == HUP)
		rotation_z(f, 10);
	else if (key == HDOWN)
		rotation_z(f, -10);
	else if (key == SPACE)
		prepare_map(f);
	put_map(f);
	return (0);
}

int					main(int ac, char **av)
{
	t_fdf			fdf;
	t_fdf			*f;

	if (ac <= 1 && ac > 2)
		put_error(1);
	f = &fdf;
	ft_bzero(f, sizeof(t_fdf));
	read_map(ac, av, f);
	init_mlx(av, f);
	prepare_map(f);
	put_map(f);
	mlx_hook(fdf.win, 2, 5, &key_handle, f);
	mlx_loop(fdf.mlx);
	deinit_mlx(f);
	return (0);
}
