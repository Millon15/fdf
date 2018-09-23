/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:03 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/23 17:10:49 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libftprintf.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

/*
**	Key numbers
*/

# define SPACE				49

enum	e_quit_sequences
{
	ESC = 53,
	Q = 12
};

enum	e_scale_chagers
{
	PLUS = 69,
	PLUS1 = 24,
	MINUS = 78,
	MINUS1 = 27
};

enum	e_rotators
{
	LEFT = 123,
	LEFT1 = 86,
	LEFT2 = 0,
	RIGHT = 124,
	RIGHT1 = 88,
	RIGHT2 = 2,
	UP = 126,
	UP1 = 91,
	UP2 = 13,
	DOWN = 125,
	DOWN1 = 84,
	DOWN2 = 1
};

enum	e_height_changers
{
	HUP = 116,
	HUP1 = 115,
	HUP2 = 258,
	HUP3 = 257,
	HDOWN = 121,
	HDOWN1 = 119,
	HDOWN2 = 256,
	HDOWN3 = 269
};

/*
**	Main structures
*/

# define SCALE				40
# define SCALE_CHANGER		1.1
# define IMG_MAX_X			(f->max.x * SCALE)
# define IMG_MAX_Y			(f->max.y * SCALE)
# define MX					(f->max)
# define MAP				(f->map)
# define VOLUME				(f->max.z)

typedef struct	s_coordinates
{
	int			x;
	int			y;

}				t_coo;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;

}				t_pixel;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;

	int			*dim;
	int			bpp;
	int			line_size;
	int			endian;

	t_list		*l;
	t_pixel		max;
	t_pixel		*map;

}				t_fdf;

void			put_error(int errnum);
void			init_mlx(char **av, t_fdf *f);
void			read_map(int ac, char **av, t_fdf *f);
void			prepare_map(t_fdf *f);
void			put_map(t_fdf *f);
void			deinit_mlx(t_fdf *f);

void			increace_map(t_fdf *f);
void			decreace_map(t_fdf *f);

void			rotation_z(t_fdf *f, long double z);
void			rotation_y(t_fdf *f, long double y);
void			rotation_x(t_fdf *f, long double x);

#endif
