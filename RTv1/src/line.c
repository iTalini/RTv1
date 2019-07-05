/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:44:27 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/29 14:44:30 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		map(char *line, t_win *win)
{
	win->width = 600;
	win->height = 600;
	win->width = ft_clamp(floatinline(line, ' ', ','), 10, 5000);
	win->height = ft_clamp(floatinline(line, ' ', '.'), 10, 5000);
	return (1);
}

int		plane(char *line, t_win *win)
{
	char	**aline;
	char	**rot;
	t_obj	*plane;

	if (!(plane = ft_memalloc(sizeof(t_obj))))
		return (0);
	plane->type = 4;
	new_obj(plane);
	if ((aline = ft_strsplit(wordinline(line, '{', '}'), ' ')) != NULL)
	{
		plane->pos.x = ft_atoi(aline[0]);
		plane->pos.y = ft_atoi(aline[1]);
		plane->pos.z = ft_atoi(aline[2]);
		free_ar(aline, 3);
	}
	if ((rot = ft_strsplit(wordinline(line, '<', '>'), ' ')) != NULL)
	{
		plane->rot.x = ft_atoi(rot[0]);
		plane->rot.y = ft_atoi(rot[1]);
		plane->rot.z = ft_atoi(rot[2]);
		free_ar(rot, 3);
	}
	plane->col = get_color(line);
	win->obj = next_obj(win, plane);
	return (1);
}

int		camera(char *line, t_win *win)
{
	char	**place;
	char	**dir;

	if (!(win->camera = ft_memalloc(sizeof(t_camera))))
		return (0);
	win->camera->place = (t_v3d){8, 1, 8};
	win->camera->dir = (t_v3d){3, 3, 2};
	if ((place = ft_strsplit(wordinline(line, '{', '}'), ' ')) != NULL)
	{
		win->camera->place.x = ft_atoi(place[0]);
		win->camera->place.y = ft_atoi(place[1]);
		win->camera->place.z = ft_atoi(place[2]);
		free_ar(place, 3);
	}
	if ((dir = ft_strsplit(wordinline(line, '<', '>'), ' ')) != NULL)
	{
		win->camera->dir.x = ft_atoi(dir[0]);
		win->camera->dir.y = ft_atoi(dir[1]);
		win->camera->dir.z = ft_atoi(dir[2]);
		free_ar(dir, 3);
	}
	if (win->camera->dir.z == win->camera->place.z)
		return (0);
	return (1);
}

int		light(char *line, t_win *win)
{
	char	**place;
	char	*word;
	t_light	*light;

	win->ln += 1;
	if (!(light = ft_memalloc(sizeof(t_light))))
		return (0);
	new_light(light);
	if ((place = ft_strsplit(wordinline(line, '{', '}'), ' ')) != NULL)
	{
		light->place.x = ft_atoi(place[0]);
		light->place.y = ft_atoi(place[1]);
		light->place.z = ft_atoi(place[2]);
		free_ar(place, 3);
	}
	light->col = get_color(line);
	word = wordinline(line, ' ', '.');
	light->power = (ft_clamp(ft_atoi(word), 0.0, 99.0)) / 100;
	light->next = NULL;
	free(word);
	win->light = next_light(win, light);
	return (1);
}

void	new_light(t_light *light)
{
	light->place.x = 2.0;
	light->place.y = 1.0;
	light->place.z = -5.0;
	light->col = (t_color){0.99609375, 0.99609375, 0.0};
	light->power = 0.7;
	light->next = NULL;
}
