/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:41:03 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/18 22:55:08 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define  FDF_H

# include <libftprintf.h>
# include <math.h>
# include <mlx.h>

# define IX		500
# define IY		500

typedef
struct	s_fdf
{
	void	*mlx;
	void	*win;

}		t_fdf;

#endif