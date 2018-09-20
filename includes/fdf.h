/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:03 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/20 13:12:15 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libftprintf.h>
# include <math.h>
# include <mlx.h>

# define SCALE				40

typedef struct	s_coordinates
{
	int			x;
	int			y;

}				t_coo;

typedef struct	s_fdf
{
	int		fd;

	void	*mlx;
	void	*win;

	t_list	*l;

	t_coo	max;
	int		**map;

}				t_fdf;

void			put_error(int errnum);
void			read_map(int ac, char **av, t_fdf *f);
void			put_map(t_fdf *f);

#endif
