/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:36:54 by akurilen          #+#    #+#             */
/*   Updated: 2018/08/14 17:36:56 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_v3d	get_cord(char *line, char i, char j, t_v3d pos)
{
	char	**aline;

	if ((aline = ft_strsplit(wordinline(line, i, j), ' ')) != NULL)
	{
		pos.x = ft_atoi(aline[0]);
		pos.y = ft_atoi(aline[1]);
		pos.z = ft_atoi(aline[2]);
		free_ar(aline, 3);
	}
	return (pos);
}

int		sphere(char *line, t_win *win)
{
	t_obj		*sphere;

	if (!(sphere = ft_memalloc(sizeof(t_obj))))
		return (0);
	sphere->type = 3;
	new_obj(sphere);
	sphere->size = (ft_clamp(floatinline(line, ' ', ','), 1.0, 50000) / 100);
	sphere->size2 = sphere->size * sphere->size;
	sphere->pos = get_cord(line, '{', '}', sphere->pos);
	sphere->col = get_color(line);
	sphere->next = NULL;
	win->obj = next_obj(win, sphere);
	return (1);
}

int		cone(char *line, t_win *win)
{
	t_obj	*cone;

	if (!(cone = ft_memalloc(sizeof(t_obj))))
		return (0);
	cone->type = 1;
	new_obj(cone);
	cone->size = (ft_clamp(floatinline(line, ' ', ','), 1.0, 50000) / 100);
	cone->size2 = cone->size * cone->size;
	cone->pos = get_cord(line, '{', '}', cone->pos);
	cone->rot = get_cord(line, '<', '>', cone->rot);
	cone->col = get_color(line);
	cone->next = NULL;
	win->obj = next_obj(win, cone);
	return (1);
}

int		cylinder(char *line, t_win *win)
{
	t_obj		*cylinder;

	if (!(cylinder = ft_memalloc(sizeof(t_obj))))
		return (0);
	cylinder->type = 2;
	new_obj(cylinder);
	cylinder->size = (ft_clamp(floatinline(line, ' ', ','), 1.0, 50000) / 100);
	cylinder->size2 = cylinder->size * cylinder->size;
	cylinder->pos = get_cord(line, '{', '}', cylinder->pos);
	cylinder->rot = get_cord(line, '<', '>', cylinder->rot);
	cylinder->col = get_color(line);
	cylinder->next = NULL;
	win->obj = next_obj(win, cylinder);
	return (1);
}
