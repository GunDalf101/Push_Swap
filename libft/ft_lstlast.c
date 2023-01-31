/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:47:18 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 01:15:17 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdlist	*ft_lstlast(t_cdlist *lst)
{
	t_cdlist	*last;

	last = lst;
	if (!last)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
