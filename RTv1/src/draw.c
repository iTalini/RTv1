/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:30:57 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/21 15:30:58 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

float	phong(t_light *li, t_v3d *nor, t_v3d *rd, t_v3d *pos)
{
	float	phong;
	float	clamp;
	float	n;
	t_v3d	ref;
	t_v3d	light;

	light.x = li->place.x - pos->x;
	light.y = li->place.y - pos->y;
	light.z = li->place.z - pos->z;
	n = 1.0 / sqrt((light.x * light.x) + (light.y * light.y)
		+ (light.z * light.z));
	light.x *= n;
	light.y *= n;
	light.z *= n;
	ref.x = rd->x - 2.0 * vecscalar(nor, rd) * nor->x;
	ref.y = rd->y - 2.0 * vecscalar(nor, rd) * nor->y;
	ref.z = rd->z - 2.0 * vecscalar(nor, rd) * nor->z;
	n = 1.0 / sqrt((ref.x * ref.x) + (ref.y * ref.y) + (ref.z * ref.z));
	ref.x *= n;
	ref.y *= n;
	ref.z *= n;
	clamp = ft_clamp(vecscalar(&ref, &light), 0.0, 1.0);
	phong = ft_clamp(pow(clamp, 50.0), 0.0, 1.0) * sqrt(li->power);
	return (phong);
}

t_v3d	get_spe(t_win *e, t_v3d *pos, t_v3d *nor)
{
	t_light	*light;
	t_v3d	spe;

	light = e->light;
	spe = (t_v3d){0.0, 0.0, 0.0};
	while (light)
	{
		spe = vecplusdub(&spe, phong(light, nor, &e->rd, pos));
		light = light->next;
	}
	spe = (t_v3d){ft_clamp(spe.x, 0.0, 1.0), ft_clamp(spe.y, 0.0, 1.0),
		ft_clamp(spe.z, 0.0, 1.0)};
	return (spe);
}

t_v3d	get_diff(t_win *e, t_v3d *pos, t_v3d *nor)
{
	t_light	*light;
	t_v3d	lig;
	t_v3d	lig_tmp;

	light = e->light;
	lig = (t_v3d){0.0, 0.0, 0.0};
	while (light)
	{
		lig_tmp = ft_lambert(light, nor, pos);
		lig = vecadd(&lig, &lig_tmp);
		light = light->next;
	}
	lig.x *= e->ln;
	lig.y *= e->ln;
	lig.z *= e->ln;
	lig = (t_v3d){ft_clamp(lig.x, 0.0, 1.0), ft_clamp(lig.y, 0.0, 1.0),
		ft_clamp(lig.z, 0.0, 1.0)};
	return (lig);
}

t_color	get_lighting(t_win *e, t_color col, t_v3d *pos)
{
	float	sha;
	t_v3d	spe;
	t_v3d	lig;
	t_v3d	nor;

	nor = (t_v3d){0.0, 1.0, 0.0};
	if (e->tmp->type == 3)
		nor = vecpass(pos, &e->tmp->pos);
	else if (e->tmp->type == 2 || e->tmp->type == 1)
		nor = (t_v3d){pos->x - e->tmp->pos.x, 0.0, pos->z
			- e->tmp->pos.z};
	vec3d_norm(&nor);
	sha = get_shadows(e, pos);
	lig = get_diff(e, pos, &nor);
	spe = get_spe(e, pos, &nor);
	lig = vecopx(&lig, sha);
	spe = vecprod(&spe, &lig);
	col = coladd(col, &spe);
	col = (t_color){ft_clamp(col.red, 0.0, 1.0), ft_clamp(col.green, 0.0, 1.0),
		ft_clamp(col.blue, 0.0, 1.0)};
	col = colprod(col, &lig);
	return (col);
}
