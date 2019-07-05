/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:04:07 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/05 14:04:08 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

float	ft_inter_sp(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float disc;
	float t1;
	float t2;

	win->dist = vecpass(ro, &obj->pos);
	win->a = vecscalar(rd, rd);
	win->b = vecscalar(&win->dist, rd);
	win->c = vecscalar(&win->dist, &win->dist) - obj->size2;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.0001)
		return (-1.0);
	t1 = (-win->b - sqrt(disc)) / win->a;
	t2 = (-win->b + sqrt(disc)) / win->a;
	if (t1 > t2)
		return (t2);
	return (t1);
}

float	ft_inter_cyl(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float disc;

	win->dist = vecpass(ro, &obj->pos);
	win->a = rd->x * rd->x + rd->z * rd->z;
	win->b = rd->x * win->dist.x + rd->z * win->dist.z;
	win->c = win->dist.x * win->dist.x + win->dist.z * win->dist.z\
			- obj->size2;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.0001)
		return (-1.0);
	disc = (-win->b - sqrt(disc)) / win->a;
	return (disc);
}

float	ft_inter_cone(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float	disc;

	win->dist = vecpass(ro, &obj->pos);
	win->a = rd->x * rd->x - rd->y * rd->y + rd->z * rd->z;
	win->b = rd->x * win->dist.x - win->dist.y * rd->y + rd->z * win->dist.z;
	win->c = win->dist.x * win->dist.x - win->dist.y\
	* win->dist.y + win->dist.z * win->dist.z;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.0001)
		return (-1.0);
	disc = (-win->b - sqrt(disc)) / win->a;
	return (disc);
}

float	ft_inter_p(t_win *win, t_obj *tmp, t_v3d *ro, t_v3d *rd)
{
	win->t0 = -((vecscalar(&tmp->rot, ro) - vecscalar(&tmp->rot, &tmp->pos))
		/ vecscalar(&tmp->rot, rd));
	if (win->t0 < 0.0001)
		return (-1.0);
	return (win->t0);
}

t_obj	*ft_inter(t_win *win, t_obj *obj, t_v3d pos, t_v3d ray)
{
	t_obj	*tmp;
	float	dist;

	tmp = NULL;
	dist = win->t;
	while (obj != NULL)
	{
		if (obj->type == 1)
			dist = ft_inter_cone(win, obj, &pos, &ray);
		else if (obj->type == 2)
			dist = ft_inter_cyl(win, obj, &pos, &ray);
		else if (obj->type == 3)
			dist = ft_inter_sp(win, obj, &pos, &ray);
		else if (obj->type == 4)
			dist = ft_inter_p(win, obj, &pos, &ray);
		if (dist > 0.0001 && dist < win->t)
		{
			tmp = obj;
			win->t = dist;
		}
		obj = obj->next;
	}
	return (tmp);
}
