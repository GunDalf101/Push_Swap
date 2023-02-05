/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:03:09 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 17:08:41 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_cdlist *lst, void (*f)(int))
{
	t_cdlist	*tmp;

	if (lst && f)
	{
		while (lst)
		{
			tmp = lst->next;
			f(lst->content);
			lst = tmp;
		}
	}
}
