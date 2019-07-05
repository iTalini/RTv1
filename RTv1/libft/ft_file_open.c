/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:07:01 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/24 16:07:04 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_file_open(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		return (-1);
	else
		fd = open(file, O_RDONLY);
	return (fd);
}
