/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:57:44 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/22 12:57:46 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		ft_sh_sp(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float disc;
	float disc1;
	float disc2;

	win->dist = vecpass(ro, &obj->pos);
	win->a = vecscalar(rd, rd);
	win->b = vecscalar(&win->dist, rd);
	win->c = vecscalar(&win->dist, &win->dist) - obj->size2;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.001)
		return (0);
	disc1 = (-win->b - sqrt(disc)) / win->a;
	disc2 = (-win->b + sqrt(disc)) / win->a;
	if (disc1 < disc2)
		return ((disc1 > 0.001) && (disc1 < win->l));
	return ((disc2 > 0.001) && (disc2 < win->l));
}

int		ft_sh_cyl(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float disc;
	float disc1;
	float disc2;

	win->dist = vecpass(ro, &obj->pos);
	win->a = rd->x * rd->x + rd->z * rd->z;
	win->b = rd->x * win->dist.x + rd->z * win->dist.z;
	win->c = win->dist.x * win->dist.x + win->dist.z * win->dist.z\
			- obj->size2;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.001)
		return (0);
	disc1 = (-win->b - sqrt(disc)) / win->a;
	disc2 = (-win->b + sqrt(disc)) / win->a;
	if (disc1 < disc2)
		return ((disc1 > 0.001) && (disc1 < win->l));
	return ((disc2 > 0.001) && (disc2 < win->l));
}

int		ft_sh_c(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd)
{
	float disc;
	float disc1;
	float disc2;

	win->dist = vecpass(ro, &obj->pos);
	win->a = rd->x * rd->x - rd->y * rd->y + rd->z * rd->z;
	win->b = rd->x * win->dist.x - win->dist.y * rd->y + rd->z * win->dist.z;
	win->c = win->dist.x * win->dist.x - win->dist.y\
	* win->dist.y + win->dist.z * win->dist.z;
	disc = win->b * win->b - win->a * win->c;
	if (disc < 0.001)
		return (0);
	disc1 = (-win->b - sqrt(disc)) / win->a;
	disc2 = (-win->b + sqrt(disc)) / win->a;
	if (disc1 < disc2)
		return ((disc1 > 0.001) && (disc1 < win->l));
	return ((disc2 > 0.001) && (disc2 < win->l));
}
