/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 00:09:49 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/27 17:23:05 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static inline int		count_digits_in_str(char *line)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (line[i] != '\0')
	{
		width++;
		while (ft_iswhitespace(line[i]))
			i++;
		if (!ft_isdigit(line[i]) && line[i] != '-')
			return (-1);
		while (ft_isdigit(line[i]))
			i++;
	}
	return (width);
}

static inline void		handle_one_line(t_fdf *f, int *m, int y, char *line)
{
	const int	mxx2 = MX.x / 2;
	const int	mxy2 = MX.y / 2;
	int			i;
	int			j;
	int			x;

	i = *m;
	j = 0;
	x = 0;
	while (line[j])
	{
		while (ft_iswhitespace(line[j]))
			j++;
		MAP[i].x = x++;
		MAP[i].y = y;
		MAP[i].z = ft_atoi(line + j);
		MAP[i].x_orig = MAP[i].x - mxx2;
		MAP[i].y_orig = MAP[i].y - mxy2;
		MAP[i].z_orig = MAP[i].z;
		while (ft_isdigit(line[j]))
			j++;
		i++;
	}
	*m = i;
}

static inline void		handle_map(t_fdf *f)
{
	t_list		*tmp;
	int			i;
	int			x;
	int			y;

	VOLUME = MX.y * MX.x;
	if ((MAP = ft_memalloc(sizeof(t_pixel) * VOLUME)) == NULL)
		put_error(6);
	tmp = f->l;
	i = 0;
	y = 0;
	while (tmp != NULL && i < VOLUME)
	{
		handle_one_line(f, &i, y, tmp->content);
		tmp = tmp->next;
		y++;
	}
}

inline void				read_map(int ac, char **av, t_fdf *f)
{
	int		ret;
	int		fd;
	char	*line;
	t_list	**tmp;

	((fd = open(av[1], O_RDONLY)) < 0) ? put_error(2) : false;
	tmp = &f->l;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		MX.y++;
		if (!MX.x
		&& (MX.x = count_digits_in_str(line)) < 0)
			put_error(7);
		else if (MX.x != count_digits_in_str(line))
			put_error(7);
		if ((*tmp = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
			put_error(6);
		tmp = &(*tmp)->next;
	}
	(ret < 0) ? put_error(5) : false;
	handle_map(f);
	(close(fd) < 0) ? put_error(10) : false;
}
