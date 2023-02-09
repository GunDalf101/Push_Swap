/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_ops3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:44:33 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/09 15:16:56 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	protecpushb(t_cdlist **stack_b, t_cdlist **stack_a, int *listaempty,
		int *listbempty)
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

void	fake_pa(t_cdlist **stack_a, t_cdlist **stack_b)
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
}

void	protecpusha(t_cdlist **stack_b, t_cdlist **stack_a, int *listaempty,
		int *listbempty)
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

void	fake_pb(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			listaempty;
	int			listbempty;
	t_cdlist	*node;
	t_cdlist	*nodext;

	listaempty = 0;
	listbempty = 0;
	protecpusha(stack_b, stack_a, &listaempty, &listbempty);
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
}
