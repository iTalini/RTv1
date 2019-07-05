/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:48:22 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/06 17:48:24 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstshift(t_list **alst)
{
	t_list	*new_first;

	if (alst != NULL && *alst != NULL)
	{
		new_first = (*alst)->next;
		free(*alst);
		*alst = new_first;
	}
}
