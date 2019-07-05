/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:22:23 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/24 12:22:25 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	ft_exit(char *s)
{
	if (s != NULL)
		ft_putstr(s);
	exit(1);
}

void	new_picture(t_win *win, char *open)
{
	win->x = 0;
	win->y = 0;
	win->wi = mlx_new_window(win->init, win->width, win->height, open);
	win->w /= 8;
	win->for_draw = 1;
	win->tmp = NULL;
}

int		expose_hook(t_win *win)
{
	all_cord(win);
	return (1);
}

int		make_win(char *open)
{
	t_win *win;

	if (!(win = ft_memalloc(sizeof(t_win))))
		return (0);
	if (!(win->init = mlx_init()))
		return (0);
	win->ln = 0;
	if (valid(open, win) == 0)
		return (0);
	new_picture(win, open);
	win->ln = 1.0 / win->ln;
	mlx_key_hook(win->wi, hook_keydown, win);
	mlx_expose_hook(win->wi, expose_hook, win);
	mlx_hook(win->wi, 17, 1L << 17, exit_x, win);
	mlx_loop(win->init);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_close(NULL));
	if (make_win(argv[1]) != 1)
		return (ft_close(NULL));
	return (0);
}
