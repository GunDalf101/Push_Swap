/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:22:52 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 03:11:47 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_cdlist *lst)
{
	int			counter;
	t_cdlist	*curr;

	counter = 0;
	curr = lst;
	while (curr != NULL)
	{
		counter++;
		curr = curr->next;
	}
	return (counter);
}
