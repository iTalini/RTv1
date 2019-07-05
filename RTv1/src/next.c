/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:00:44 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/01 17:00:46 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_obj		*next_obj(t_win *win, t_obj *obj)
{
	t_obj *help;

	help = win->obj;
	if (win->obj == NULL)
		return (obj);
	while (win->obj->next != NULL)
		win->obj = win->obj->next;
	win->obj->next = obj;
	return (help);
}

t_light		*next_light(t_win *win, t_light *light)
{
	t_light *help;

	help = win->light;
	if (win->light == NULL)
		return (light);
	while (win->light->next != NULL)
		win->light = win->light->next;
	win->light->next = light;
	return (help);
}
