/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:49:56 by akurilen          #+#    #+#             */
/*   Updated: 2018/02/07 20:58:22 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"

# define LIMIT_FD 4864

typedef struct		s_fd
{
	int			fd;
	int			start;
	t_list		*lst;
	struct s_fd	*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
