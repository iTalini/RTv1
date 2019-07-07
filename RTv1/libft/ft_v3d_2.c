/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:25:20 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/05 13:25:22 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec3d_norm(t_v3d *v)
{
	float n;

	n = 1.0 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

float	vecdistance(t_v3d *a, t_v3d *b)
{
	float	distance;

	distance = sqrt((a->x - b->x) * (a->x - b->x) + \
		(a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
	return (distance);
}

float	vecscalar(t_v3d *v1, t_v3d *v2)
{
	float	res;

	res = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (res);
}

t_v3d	vecplusdub(t_v3d *a, float x)
{
	t_v3d v;

	v.x = a->x + x;
	v.y = a->y + x;
	v.z = a->z + x;
	return (v);
}

t_v3d	vecreflect(t_v3d *i, t_v3d *n)
{
	t_v3d	v;

	v.x = i->x - 2.0 * vecscalar(n, i) * n->x;
	v.y = i->y - 2.0 * vecscalar(n, i) * n->y;
	v.z = i->z - 2.0 * vecscalar(n, i) * n->z;
	return (v);
}
