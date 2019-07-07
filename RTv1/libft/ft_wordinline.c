/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordinline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:11:46 by akurilen          #+#    #+#             */
/*   Updated: 2018/08/12 15:11:48 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*wordinline(char *line, char a, char b)
{
	char	*ans;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i] && line[i] != b)
		if (line[i] == a)
			j = i;
	if (line[j] != a)
		return (NULL);
	i = 0;
	while (line && line[i + j] != b)
		i++;
	if (line[i + j] != b)
		return (NULL);
	ans = ft_memalloc(sizeof(char) * i + 1);
	i = -1;
	while (line && line[++j] != b)
		ans[++i] = line[j];
	ans[++i] = '\0';
	return (ans);
}

float	floatinline(char *line, char a, char b)
{
	char	*ans;
	float	doub;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (line[++j] && line[j] != b)
		if (line[j] == a)
			i = j;
	j = 0;
	while (line[i + j] && line[i + j] != b)
		j++;
	ans = ft_memalloc(sizeof(char) * j + 1);
	j = -1;
	i--;
	while (line[++i] && line[i] != b)
		ans[++j] = line[i];
	doub = (float)ft_atoi(ans);
	ft_strdel(&ans);
	free(ans);
	return (doub);
}
