/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:47:46 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/03 15:47:47 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_color	ft_average(t_color tab)
{
	t_color ans;

	ans.red = ft_clamp(tab.red, 0.0, 1.0);
	ans.green = ft_clamp(tab.green, 0.0, 1.0);
	ans.blue = ft_clamp(tab.blue, 0.0, 1.0);
	return (ans);
}

void	set_ray(t_win *win, float x, float y)
{
	float	u;
	float	v;

	u = (win->width - x * 2.0) / win->height;
	v = (win->height - y * 2.0) / win->height;
	win->k = vecpass(&win->camera->dir, &win->camera->place);
	vec3d_norm(&win->k);
	win->i = vecross(&win->k, &(t_v3d){0.0, 1.0, 0.0});
	vec3d_norm(&win->i);
	win->j = vecross(&win->i, &win->k);
	win->rd.x = u * win->i.x + v * win->j.x + 2.0 * win->k.x;
	win->rd.y = u * win->i.y + v * win->j.y + 2.0 * win->k.y;
	win->rd.z = u * win->i.z + v * win->j.z + 2.0 * win->k.z;
	win->tmp = NULL;
}

int		ray_trace(t_win *win, t_obj *obj, int x, int y)
{
	t_v3d	pos;
	t_color	col;

	col = (t_color){0, 0, 0};
	set_ray(win, x, y);
	win->t = 10000.0;
	pos = (t_v3d){0, 0, 0};
	win->tmp = ft_inter(win, obj, win->camera->place, win->rd);
	if ((win->t > 0.0001) && win->tmp)
	{
		col = (t_color){win->tmp->col.red, win->tmp->col.green,\
			win->tmp->col.blue};
		if (win->t < 10000.0)
		{
			pos = (t_v3d){win->camera->place.x + win->t * win->rd.x,\
				win->camera->place.y + win->t * win->rd.y,\
				win->camera->place.z + win->t * win->rd.z};
			col = get_lighting(win, col, &pos);
		}
	}
	win->col = ft_average(col);
	ft_put_pixel(win, x, y);
	return (0);
}

void	all_cord(t_win *map)
{
	float	x;
	float	y;
	t_obj	*obj;

	obj = map->obj;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ray_trace(map, obj, x, y);
	}
}
