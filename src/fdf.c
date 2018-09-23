/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/23 17:07:40 by vbrazas          ###   ########.fr       */
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

static inline int	key_hook(int key, t_fdf *f)
{
	if (key == ESC || key == Q)
		exit(0);
	else if (key == PLUS || key == PLUS1)
		increace_map(f);
	else if (key == MINUS || key == MINUS1)
		decreace_map(f);
	else if (key == LEFT || key == LEFT1 || key == LEFT2)
		rotation_y(f, 10);
	else if (key == RIGHT || key == RIGHT1 || key == RIGHT2)
		rotation_y(f, -10);
	else if (key == UP || key == UP1 || key == UP2)
		rotation_x(f, 10);
	else if (key == DOWN || key == DOWN1 || key == DOWN2)
		rotation_x(f, -10);
	else if (key == HUP || key == HUP1 || key == HUP2 || key == HUP3)
		rotation_z(f, 10);
	else if (key == HDOWN || key == HDOWN1 || key == HDOWN2 || key == HDOWN3)
		rotation_z(f, -10);
	put_map(f);
	return (0);
}

int					main(int ac, char **av)
{
	t_fdf			f;

	if (ac <= 1 && ac > 2)
		put_error(1);
	read_map(ac, av, &f);
	init_mlx(av, &f);
	prepare_map(&f);
	put_map(&f);
	mlx_key_hook(f.win, &key_hook, &f);
	mlx_loop(f.mlx);
	deinit_mlx(&f);
	return (0);
}
