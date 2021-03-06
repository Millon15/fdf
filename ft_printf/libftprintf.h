/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:15:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/23 05:02:25 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"

/*
*****************************************************************************
********************************** FT_PRINTF ********************************
*****************************************************************************
*/

int					ft_printf(const char *convstr, ...);
int					ft_dprintf(int fd, const char *convstr, ...);

#endif
