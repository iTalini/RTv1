/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:32:33 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/30 14:32:34 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

float	shadows(t_win *e, t_v3d *pos, t_v3d *lpos)
{
	t_obj	*lobj;
	int		tmp;
	int		sha;
	t_v3d	light;

	lobj = e->obj;
	tmp = 0;
	sha = 0;
	light = vecpass(lpos, pos);
	e->l = veclength(&light);
	light = vecopdiv(&light, e->l);
	while (lobj)
	{
		if (lobj->type == 3)
			tmp = ft_sh_sp(e, lobj, pos, &light);
		else if (lobj->type == 2)
			tmp = ft_sh_cyl(e, lobj, pos, &light);
		else if (lobj->type == 1)
			tmp = ft_sh_c(e, lobj, pos, &light);
		sha = (tmp == 1 ? 1 : sha);
		lobj = lobj->next;
	}
	return (sha);
}

float	get_shadows(t_win *e, t_v3d *pos)
{
	t_light	*light;
	float	sha;
	float	tmp;

	light = e->light;
	sha = 1.0;
	while (light)
	{
		tmp = shadows(e, pos, &light->place);
		if (tmp == 1)
			sha -= (light->power + e->ln) / 2.0;
		light = light->next;
	}
	sha = ft_clamp(sha, 0.0, 1.0);
	return (sha);
}

t_color	coladd(t_color a, t_v3d *b)
{
	t_color	v;

	v.red = a.red + b->x;
	v.green = a.green + b->y;
	v.blue = a.blue + b->z;
	return (v);
}

t_color	colprod(t_color a, t_v3d *b)
{
	t_color	v;

	v.red = a.red * b->x;
	v.green = a.green * b->y;
	v.blue = a.blue * b->z;
	return (v);
}

t_v3d	ft_lambert(t_light *light, t_v3d *nor, t_v3d *pos)
{
	t_v3d	lambert;
	t_v3d	lig;
	float	value;
	float	dist;

	dist = sqrt((pos->x - light->place.x) * (pos->x -
		light->place.x) + (pos->y - light->place.y) *
	(pos->y - light->place.y) + (pos->z - light->place.z) *
	(pos->z - light->place.z));
	dist = ft_clamp(sqrt(1.0 / (dist * (1.0 - light->power))), 0.0, 1.0);
	lig = vecpass(&light->place, pos);
	vec3d_norm(&lig);
	if (nor->x == 0.0 && nor->y == 1.0 && nor->z == 0.0)
		value = 1.0;
	else
		value = ft_clamp(vecscalar(nor, &lig), 0.0, 1.0);
	lambert.x = light->col.red * value;
	lambert.y = light->col.green * value;
	lambert.z = light->col.blue * value;
	lambert = vecopx(&lambert, light->power);
	lambert = vecopx(&lambert, dist);
	return (lambert);
}
