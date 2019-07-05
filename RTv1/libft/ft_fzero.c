/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:13:24 by akurilen          #+#    #+#             */
/*   Updated: 2018/09/09 15:13:25 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fzero(float *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0.0f;
		i++;
	}
}
