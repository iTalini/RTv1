/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:20:42 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/24 12:20:44 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_obj
{
	int				type;
	t_v3d			pos;
	t_v3d			rot;
	t_color			col;
	float			size;
	float			size2;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_light
{
	t_v3d			place;
	t_v3d			dir;
	t_color			col;
	float			power;
	float			r;
	struct s_light	*next;
}					t_light;

typedef struct		s_camera
{
	t_v3d			place;
	t_v3d			dir;
}					t_camera;

typedef struct		s_win
{
	void			*wi;
	void			*init;
	float			ln;
	float			l;
	short int		width;
	short int		height;
	t_v3d			dist;
	int				x;
	int				y;
	int				w;
	t_color			col;
	int				for_draw;
	t_v3d			i;
	t_v3d			j;
	t_v3d			k;
	t_v3d			rd;
	t_obj			*obj;
	t_obj			*tmp;
	t_light			*light;
	t_camera		*camera;
	float			a;
	float			b;
	float			c;
	float			h;
	float			t0;
	t_v3d			norm;
	float			t;
}					t_win;

void				all_cord(t_win *map);
void				vect_x(t_v3d *xyz, t_v3d *rot, float invert);
void				vect_y(t_v3d *xyz, t_v3d *rot, float invert);
int					valid(char *open, t_win *win);
t_v3d				colopx(t_color *a, float x);
void				ft_put_pixel(t_win *win, int x, int y);
t_color				get_lighting(t_win *e, t_color col, t_v3d *pos);
float				get_shadows(t_win *e, t_v3d *pos);
t_v3d				get_diff(t_win *e, t_v3d *pos, t_v3d *nor);
t_v3d				get_spe(t_win *e, t_v3d *pos, t_v3d *nor);
float				phong(t_light *light, t_v3d *nor, t_v3d *rd, t_v3d *pos);
void				set_ray(t_win *win, float x, float y);
void				new_picture(t_win *win, char *open);
void				ft_exit(char *s);
t_v3d				ft_lambert(t_light *light, t_v3d *nor, t_v3d *pos);
t_color				ft_average(t_color tab);
t_obj				*ft_inter(t_win *win, t_obj *obj, t_v3d ray, t_v3d pos);
int					ray_trace(t_win *win, t_obj *obj, int x, int y);
float				ft_inter_sp(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
float				ft_inter_cyl(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
float				ft_inter_cone(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
float				ft_inter_p(t_win *win, t_obj *tmp, t_v3d *ray, t_v3d *pos);
int					ft_sh_sp(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
int					ft_sh_cyl(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
int					ft_sh_c(t_win *win, t_obj *obj, t_v3d *ro, t_v3d *rd);
t_color				coladd(t_color	a, t_v3d *b);
t_color				colprod(t_color a, t_v3d *b);
int					key_hook(int keycode, t_win *win);
int					exit_x(void *par);
int					sphere(char *line, t_win *win);
int					cone(char *line, t_win *win);
int					cylinder(char *line, t_win *win);
int					camera(char *line, t_win *win);
int					light(char *line, t_win *win);
int					hook_keydown(int key, t_win *win);
int					check_file(char *line, t_win *win);
int					map(char *line, t_win *win);
int					plane(char *line, t_win *win);
t_obj				*next_obj(t_win *win, t_obj *obj);
t_light				*next_light(t_win *win, t_light *light);
t_color				get_color(char *line);
void				new_obj(t_obj *obj);
void				new_light(t_light *light);
int					make_win(char *open);
int					expose_hook(t_win *win);
float				shadows(t_win *e, t_v3d *pos, t_v3d *lpos);
void				make_minus(t_win *win, int key);
void				make_plus(t_win *win, int key);
t_v3d				get_cord(char *line, char i, char j, t_v3d pos);
#endif
