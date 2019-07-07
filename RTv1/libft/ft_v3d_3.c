/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:02:33 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/21 19:02:35 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	veclength(t_v3d *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_v3d	vecopdiv(t_v3d *a, float x)
{
	t_v3d v;

	v.x = a->x / x;
	v.y = a->y / x;
	v.z = a->z / x;
	return (v);
}
