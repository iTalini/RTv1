/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:17:25 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 16:19:18 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float		calc_zap(const char *str, int i, float res)
{
	int		col;
	int		f;
	float	after;

	col = 0;
	if (str[i] == ',' || str[i] == '.')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (res);
	while (str[i + col] >= '0' && str[i + col] <= '9')
	{
		f = -2;
		after = (str[i + col] - 48);
		while (++f < col)
			after = after / 10;
		res = res + after;
		col++;
	}
	return (res);
}

static float		calc(const char *str)
{
	int		i;
	float	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if ((str[i] == ',' || str[i] == '.') && (str[i - 1] >= '0' &&
		str[i - 1] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		res = calc_zap(str, i, res);
	return (res * sign);
}

float				ft_atoi(const char *str)
{
	float	res;
	int		i;

	i = 0;
	res = 0;
	if (!str || str == NULL)
		return (0);
	if (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
			i++;
		if (((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' &&
				str[i + 1] <= '9')) || (str[i] >= '0' && str[i] <= '9') ||
				(str[i] == ',') || (str[i] == '.'))
			res = calc(&str[i]);
		return (res);
	}
	return (res);
}
