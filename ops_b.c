/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:00:18 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 16:45:55 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	protecpushb(t_cdlist **stack_b, t_cdlist **stack_a, \
int *listaempty, int *listbempty)
{
	t_cdlist	*node;

	node = *stack_a;
	if (!*stack_b)
		*listbempty = 1;
	if (!*stack_a)
		*listaempty = 1;
	else if (!node->next)
		*listaempty = 2;
}

void	pa(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			listaempty;
	int			listbempty;
	t_cdlist	*node;
	t_cdlist	*nodext;

	listaempty = 0;
	listbempty = 0;
	protecpushb(stack_b, stack_a, &listaempty, &listbempty);
	if (listaempty == 1)
		return ;
	node = *stack_a;
	if (listaempty != 2)
	{
		nodext = node->next;
		nodext->prev = NULL;
	}
	else
		nodext = NULL;
	ft_lstadd_front(stack_b, node);
	if (listbempty == 0)
		node->next->prev = node;
	*stack_a = nodext;
	*stack_b = node;
	ft_printf("pa\n");
}

void	sb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;

	node = *stack_b;
	nodo = node->next;
	node->next = nodo->next;
	nodo->next = node;
	node->next->prev = node;
	node->prev = nodo;
	nodo->prev = NULL;
	*stack_b = nodo;
	ft_printf("sb\n");
}

void	rb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodext;

	node = *stack_b;
	nodo = ft_lstlast(*stack_b);
	nodext = node->next;
	nodo->next = node;
	node->next = NULL;
	node->prev = nodo;
	nodext->prev = NULL;
	*stack_b = nodext;
	ft_printf("rb\n");
}

void	rrb(t_cdlist **stack_b)
{
	t_cdlist	*node;
	t_cdlist	*nodo;
	t_cdlist	*nodev;

	node = *stack_b;
	nodo = ft_lstlast(*stack_b);
	nodev = nodo->prev;
	nodo->next = node;
	nodo->prev = NULL;
	nodev->next = NULL;
	node->prev = nodo;
	*stack_b = nodo;
	ft_printf("rrb\n");
}
