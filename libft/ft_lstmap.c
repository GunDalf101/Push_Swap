/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 04:58:25 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 17:11:14 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdlist	*ft_lstmap(t_cdlist *lst, int (*f)(int))
{
	t_cdlist	*newlst;
	t_cdlist	*newel;

	if (!f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newel = ft_lstnew (f(lst->content));
		if (!newel)
		{
			ft_lstclear(&newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newel);
		lst = lst->next;
	}
	return (newlst);
}
