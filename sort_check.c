/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:17:16 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/07 12:23:05 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_checker(t_cdlist **stack_a)
{
	t_cdlist	*node;

	node = *stack_a;
	while (node->next)
	{
		if (node->content > node->next->content)
			return ;
		node = node->next;
	}
	ft_lstclear(stack_a);
	exit (0);
}

void	sa_rra_or(t_cdlist **stack_a, int which)
{
	if (which == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (which == 1)
	{
		rra(stack_a);
		sa(stack_a);
	}
}
