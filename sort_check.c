/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:17:16 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 13:35:15 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_checker(t_cdlist **stack_a)
{
	t_cdlist	*node;

	node = *stack_a;
	while(node->next)
	{
		if (node->content > node->next->content)
			return ;
		node = node->next;
	}
	exit (0);
}