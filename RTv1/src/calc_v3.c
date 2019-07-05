/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_v3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:41:26 by akurilen          #+#    #+#             */
/*   Updated: 2018/08/12 12:41:28 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	vect_y(t_v3d *xyz, t_v3d *rot, float invert)
{
	float y;
	float z;

	y = xyz->y * cos(invert * rot->x)
		- xyz->z * sin(invert * rot->x);
	z = xyz->y * sin(invert * rot->x)
		+ xyz->z * cos(invert * rot->x);
	xyz->y = y;
	xyz->z = z;
}

void	vect_x(t_v3d *xyz, t_v3d *rot, float invert)
{
	float x;
	float z;

	x = xyz->x * cos(invert * rot->y)
		+ xyz->z * sin(invert * rot->y);
	z = xyz->x * -sin(invert * rot->y)
		+ xyz->z * cos(invert * rot->y);
	xyz->x = x;
	xyz->z = z;
}
