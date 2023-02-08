/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_ops_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:42:15 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/07 21:11:27 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	fake_rra(t_cdlist **stack_a)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodev;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	node = *stack_a;
	nodo = ft_lstlast(*stack_a);
	nodev = nodo->prev;
	nodo->next = node;
	nodo->prev = NULL;
	nodev->next = NULL;
	node->prev = nodo;
	*stack_a = nodo;
}

void	fake_rrb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodev;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	node = *stack_b;
	nodo = ft_lstlast(*stack_b);
	nodev = nodo->prev;
	nodo->next = node;
	nodo->prev = NULL;
	nodev->next = NULL;
	node->prev = nodo;
	*stack_b = nodo;
}

void	fake_rb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodext;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	node = *stack_b;
	nodo = ft_lstlast(*stack_b);
	nodext = node->next;
	nodo->next = node;
	node->next = NULL;
	node->prev = nodo;
	nodext->prev = NULL;
	*stack_b = nodext;
}

void	fake_ra(t_cdlist **stack_a)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodext;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	node = *stack_a;
	nodo = ft_lstlast(*stack_a);
	nodext = node->next;
	nodo->next = node;
	node->next = NULL;
	node->prev = nodo;
	nodext->prev = NULL;
	*stack_a = nodext;
}
