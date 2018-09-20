/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 00:09:49 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/20 09:36:07 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static inline int	*read_nums_from_str(char *line, int width)
{
	int		i;
	int		j;
	int		*intstr;

	i = 0;
	j = 0;
	if ((intstr = malloc(sizeof(int) * width)) == NULL)
		put_error(6);
	while (line[i] != '\0')
	{
		while (ft_iswhitespace(line[i]))
			i++;
		intstr[j++] = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
	}
	return (intstr);
}

static inline int	count_digits_in_str(char *line)
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
		if (!ft_isdigit(line[i]))
			return (-1);
		while (ft_isdigit(line[i]))
			i++;
	}
	return (width);
}

static inline void	handle_map(t_fdf *f)
{
	t_list	*tmp;
	int		i;

	if ((f->map = malloc(sizeof(int*) * (f->max.y + 1))) == NULL)
		put_error(6);
	f->map[f->max.y] = NULL;
	tmp = f->l;
	if ((f->max.x = count_digits_in_str(tmp->content)) < 0)
		put_error(7);
	i = 0;
	while (tmp != NULL && i < f->max.y)
	{
		if (f->max.x != count_digits_in_str(tmp->content))
			put_error(7);
		f->map[i++] = read_nums_from_str(tmp->content, f->max.x);
		tmp = tmp->next;
	}
}

inline void			read_map(int ac, char **av, t_fdf *f)
{
	int		ret;
	char	*line;
	t_list	**tmp;

	tmp = &f->l;
	f->max.y = 0;
	while ((ret = get_next_line(f->fd, &line)) > 0)
	{
		f->max.y++;
		if ((*tmp = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
			put_error(6);
		tmp = &(*tmp)->next;
	}
	if (ret < 0)
		put_error(5);
	handle_map(f);
}
