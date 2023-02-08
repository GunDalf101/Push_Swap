/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:48 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 23:28:33 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	fake_rr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	fake_ra(stack_a);
	fake_rb(stack_b);
}

void	fake_rrr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	fake_rra(stack_a);
	fake_rrb(stack_b);
}

void	fake_sa(t_cdlist **stack_a)
{
	t_cdlist	*node;
	t_cdlist	*nodo;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	node = *stack_a;
	nodo = node->next;
	node->next = nodo->next;
	nodo->next = node;
	if (node->next)
		node->next->prev = node;
	node->prev = nodo;
	nodo->prev = NULL;
	*stack_a = nodo;
}

void	fake_sb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	node = *stack_b;
	nodo = node->next;
	node->next = nodo->next;
	nodo->next = node;
	if (node->next)
		node->next->prev = node;
	node->prev = nodo;
	nodo->prev = NULL;
	*stack_b = nodo;
}

void	fake_ss(t_cdlist **stack_a, t_cdlist **stack_b)
{
	fake_sa(stack_a);
	fake_sb(stack_b);
}
