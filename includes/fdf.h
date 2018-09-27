/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:03 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/27 17:17:47 by vbrazas          ###   ########.fr       */
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
	HDOWN = 121,
};

/*
**	Main structures
*/

# define SCALE				40
# define SCALE_CHANGER		1.1
# define MX					(f->max)
# define ANGLE				(f->angle)
# define MAP				(f->map)
# define VOLUME				(f->max.z)
# define WLEN				(f->window_length)
# define WHEI				(f->window_height)

typedef struct	s_coordinates
{
	int			x;
	int			y;

}				t_coo;

typedef struct	s_angle
{
	long double		x;
	long double		y;
	long double		z;

}				t_angle;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			x_orig;
	int			y_orig;
	int			z_orig;
	int			x_back;
	int			y_back;
	int			z_back;

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

	int			window_length;
	int			window_height;

	t_list		*l;
	t_pixel		max;
	t_angle		angle;
	t_pixel		*map;

}				t_fdf;

void			put_error(int errnum);
void			init_mlx(char **av, t_fdf *f);
void			read_map(int ac, char **av, t_fdf *f);
void			prepare_map(t_fdf *f);
void			put_map(t_fdf *f);
void			deinit_mlx(t_fdf *f);

void			increase_map(t_fdf *f);
void			decrease_map(t_fdf *f);

void			put_center(t_fdf *f);

void			rotation_z(t_fdf *f, float z);
void			rotation_y(t_fdf *f, float y);
void			rotation_x(t_fdf *f, float x);

#endif
