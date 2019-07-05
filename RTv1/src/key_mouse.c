/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:54:17 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/24 15:54:19 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	make_plus(t_win *win, int key)
{
	t_v3d vect;

	vect = (t_v3d){1.0, 1.0, 1.0};
	if (key == 126)
		vect_y(&win->camera->place, &vect, -0.05);
	else if (key == 124)
		vect_x(&win->camera->place, &vect, -0.05);
	else if (key == 69)
	{
		if (win->camera->place.z > win->camera->dir.z
			|| win->camera->place.z == win->camera->dir.z)
		{
			win->camera->place.z--;
			if (win->camera->place.z == win->camera->dir.z)
				win->camera->place.z--;
		}
		else if (win->camera->place.z < win->camera->dir.z)
		{
			win->camera->place.z++;
			if (win->camera->place.z == win->camera->dir.z)
				win->camera->place.z++;
		}
	}
	all_cord(win);
}

void	make_minus(t_win *win, int key)
{
	t_v3d vect;

	vect = (t_v3d){1.0, 1.0, 1.0};
	if (key == 125)
		vect_y(&win->camera->place, &vect, 0.05);
	else if (key == 123)
		vect_x(&win->camera->place, &vect, 0.05);
	else if (key == 78)
	{
		if (win->camera->place.z > win->camera->dir.z
			|| win->camera->place.z == win->camera->dir.z)
		{
			win->camera->place.z++;
			if (win->camera->place.z == win->camera->dir.z)
				win->camera->place.z++;
		}
		else if (win->camera->place.z < win->camera->dir.z)
		{
			win->camera->place.z--;
			if (win->camera->place.z == win->camera->dir.z)
				win->camera->place.z--;
		}
	}
	all_cord(win);
}

int		hook_keydown(int key, t_win *win)
{
	(void)win;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126 || key == 124 || key == 69)
		make_plus(win, key);
	if (key == 125 || key == 123 || key == 78)
		make_minus(win, key);
	return (0);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
