/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:06 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 01:27:09 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_cdlist **lst, t_cdlist *new)
{
	t_cdlist	*last;

	last = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
