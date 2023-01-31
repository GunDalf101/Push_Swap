/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 04:58:25 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 01:15:21 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_cdlist	*ft_lstmap(t_cdlist *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_cdlist	*newlst;
// 	t_cdlist	*newel;

// 	if (!f || !del)
// 		return (NULL);
// 	newlst = NULL;
// 	while (lst)
// 	{
// 		newel = ft_lstnew (f(lst->content));
// 		if (!newel)
// 		{
// 			ft_lstclear(&newlst, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&newlst, newel);
// 		lst = lst->next;
// 	}
// 	return (newlst);
// }
