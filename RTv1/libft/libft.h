/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:31:39 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/28 18:20:51 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define BUFF_SIZE 200

typedef struct		s_v3d
{
	float			x;
	float			y;
	float			z;
}					t_v3d;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_list
{
	char			alf;
	char			num;
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_file_open(char *file);
int					ft_freeget(char *temp);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_getnbr(char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
float				ft_atoi(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *hay, const char *ned);
size_t				ft_strlen(const char *str);
char				*ft_strnstr(const char *hay, const char *ned, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(char const *src);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_minus_plus(int i);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list	**alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list	*lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_iswhitespace(int c);
int					ft_sqrt(int nb);
int					*ft_range(int min, int max);
void				ft_swap(int *a, int *b);
int					ft_lstcount(t_list *alst);
void				ft_lstaddend(t_list **alst, t_list *new);
int					get_next_line(int const fd, char **line);
int					ft_lerpi(int first, int second, float p);
float				ft_ilerp(float val, float first, float second);
int					ft_abs(int i);
int					ft_splitdel(char ***split);
void				ft_lstrev(t_list **alst);
int					ft_countwords(char *str, char sep);
void				free_ar(char **res, int len);
t_list				*ft_lstln(void *content, size_t content_size);
void				ft_lstshift(t_list **alst);
int					ft_close(char *s);
char				*wordinline(char *line, char a, char b);
float				floatinline(char *line, char a, char b);
t_v3d				vecadd(t_v3d *a, t_v3d *b);
t_v3d				vecprod(t_v3d *a, t_v3d *b);
t_v3d				vecopx(t_v3d *a, float x);
t_v3d				vecpass(t_v3d *a, t_v3d *b);
void				vec3d_norm(t_v3d *v);
t_v3d				vecross(t_v3d *a, t_v3d *b);
float				ft_clamp(float value, float min, float max);
float				ft_pow(float i, int x);
float				vecscalar(t_v3d *v1, t_v3d *v2);
float				vecdistance(t_v3d *a, t_v3d *b);
void				ft_fzero(float *s, int n);
t_v3d				vecopdiv(t_v3d *a, float x);
float				veclength(t_v3d *vec);
t_v3d				vecplusdub(t_v3d *a, float x);
#endif
