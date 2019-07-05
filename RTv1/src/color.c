/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:59:07 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/29 17:59:08 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	ft_put_pixel(t_win *win, int x, int y)
{
	int		color;

	color = (int)(win->col.blue * 256) % 256;
	color += ((int)(win->col.green * 256) % 256) * 256;
	color += ((int)(win->col.red * 256) % 256) * 256 * 256;
	mlx_pixel_put(win->init, win->wi, x, y, color);
}

t_v3d	colopx(t_color *a, float x)
{
	t_v3d	v;

	v.x = a->red * x;
	v.y = a->green * x;
	v.z = a->blue * x;
	return (v);
}

t_color	get_color(char *line)
{
	t_color	color;
	char	**col;

	color = (t_color){0.99609375, 0.99609375, 0.0};
	if ((col = ft_strsplit(wordinline(line, '(', ')'), ' ')) != NULL)
	{
		color.red = ft_clamp(ft_atoi(col[0]) / 256.0, 0.0, 1.0);
		color.green = ft_clamp(ft_atoi(col[1]) / 256.0, 0.0, 1.0);
		color.blue = ft_clamp(ft_atoi(col[2]) / 256.0, 0.0, 1.0);
		free_ar(col, 3);
	}
	return (color);
}
