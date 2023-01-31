/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 04:49:31 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 01:14:55 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_cdlist **lst, void (*del)(void *))
// {
// 	t_cdlist	*temp;

// 	if (!lst || !*lst || !del)
// 		return ;
// 	if (lst && del)
// 	{
// 		while (*lst)
// 		{
// 			temp = (*lst)->next;
// 			del((*lst)->content);
// 			free(*lst);
// 			*lst = temp;
// 		}
// 	}
// 	*lst = NULL;
// }
