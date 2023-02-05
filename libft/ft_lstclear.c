/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 04:49:31 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 15:17:35 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_cdlist **lst)
{
	t_cdlist	*temp;

	if (!lst || !*lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
	}
	*lst = NULL;
}
