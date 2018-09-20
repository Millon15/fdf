/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:04 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/20 13:11:21 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				put_error(int errnum)
{
	const char		usage[] = "./fdf <map_name>";

	(errnum == 1) ? ft_dprintf(2, "%s\n", usage) : 0;
	(errnum == 2) ? ft_dprintf(2, "open failed\n") : 0;
	(errnum == 3) ? ft_dprintf(2, "mlx_init failed\n") : 0;
	(errnum == 4) ? ft_dprintf(2, "mlx_new_window failed\n") : 0;
	(errnum == 5) ? ft_dprintf(2, "get_next_line failed\n") : 0;
	(errnum == 6) ? ft_dprintf(2, "malloc failed\n") : 0;
	if (errnum == 7)
		ft_dprintf(2, "wrong number of ints in string in map\n");
	(errnum == 8) ? ft_dprintf(2, "mlx_new_image failed\n") : 0;
	exit(0);
}

static inline int	key_hook(int key, t_fdf *f)
{
	return (0);
}

int					main(int ac, char **av)
{
	t_fdf	f;

	if (ac <= 1 && ac > 2)
		put_error(1);
	if ((f.fd = open(av[1], O_RDONLY)) < 0)
		put_error(2);
	read_map(ac, av, &f);
	if ((f.mlx = mlx_init()) == NULL)
		put_error(3);
	if ((f.win = mlx_new_window(f.mlx, f.max.x * SCALE, f.max.y * SCALE, av[1])) == NULL)
		put_error(4);
	put_map(&f);
	mlx_key_hook(f.win, &key_hook, &f);
	mlx_loop(f.mlx);
	mlx_destroy_window(f.mlx, f.win);
	close(f.fd);
	return (0);
}
