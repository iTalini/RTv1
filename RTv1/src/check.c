/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:11:29 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/01 16:13:06 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		check_file(char *line, t_win *win)
{
	if (!ft_strncmp(line, "Map: ", 5) && !map(line, win))
		return (0);
	else if (!ft_strncmp(line, "Camera: ", 8) && !camera(line, win))
		return (0);
	else if (!ft_strncmp(line, "Light: ", 7) && !light(line, win))
		return (0);
	else if (!ft_strncmp(line, "Cone: ", 6) && !cone(line, win))
		return (0);
	else if (!ft_strncmp(line, "Сylinder: ", 10) && !cylinder(line, win))
		return (0);
	else if (!ft_strncmp(line, "Sphere: ", 8) && !sphere(line, win))
		return (0);
	else if (!ft_strncmp(line, "Plane: ", 6) && !plane(line, win))
		return (0);
	return (1);
}

void	new_obj(t_obj *obj)
{
	obj->size = 3;
	obj->pos = (t_v3d){0.0, -1.0, 0.0};
	obj->rot = (t_v3d){0.0, 1.0, 0.0};
	obj->col = (t_color){0.99609375, 0.99609375, 0.0};
}

int		valid(char *open, t_win *win)
{
	int		fd;
	int		i;
	int		num;
	char	*line;

	num = 0;
	if ((fd = ft_file_open(open)) == -1)
		return (0);
	line = NULL;
	while ((i = get_next_line(fd, &line)) == 1)
	{
		if ((++num == 1 && ft_strncmp(line, "Map: ", 5)) ||
			check_file(line, win) == 0 ||
			(num == 2 && ft_strncmp(line, "Camera: ", 8)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
