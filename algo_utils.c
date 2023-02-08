/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:04:54 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/07 21:07:50 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_updater(t_cdlist **stack)
{
	t_cdlist	*tmp;
	int			pos;
	int			size;

	size = ft_lstsize(*stack);
	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		if (pos <= size / 2)
			tmp->steps = pos;
		else if (pos > size / 2)
				tmp->steps = size - pos;
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

void	world_vs_minsteps(t_helper *container, int comparer)
{
	if (comparer < container->minsteps)
	{
		container->minsteps = comparer;
		container->minb = container->tmpmin;
		container->mina = container->tmpa;
	}
}

void	b_iterator(t_helper *container, t_cdlist **stack_b)
{
	container->tmpb = *stack_b;
	while (container->tmpb)
	{
		if (absolute(container->tmpa->content - container->tmpb->content) \
		< absolute(container->tmpa->content - container->tmpmin->content))
			container->tmpmin = container->tmpb;
		container->tmpb = container->tmpb->next;
	}
}

void	min_locker(t_helper *container)
{
	if (container->tmpa->pos <= container->sizea / 2 && container->tmpmin->pos \
	<= container->sizeb / 2 && container->tmpa->pos > container->tmpmin->pos)
		world_vs_minsteps (container, container->tmpa->steps);
	else if (container->tmpa->pos <= container->sizea / 2 && container->\
	tmpmin->pos <= container->sizeb / 2 && container->tmpa->pos <= \
	container->tmpmin->pos)
		world_vs_minsteps (container, container->tmpmin->steps);
	else if (container->tmpa->pos > container->sizea / 2 && container->tmpmin->\
	pos > container->sizeb / 2 && (container->sizea - container->tmpa->pos) >= \
	(container->sizeb - container->tmpmin->pos))
		world_vs_minsteps (container, container->tmpa->steps);
	else if (container->tmpa->pos > container->sizea / 2 && container->tmpmin->\
	pos > container->sizeb / 2 && (container->sizea - container->tmpa->pos) < \
	(container->sizeb - container->tmpmin->pos))
		world_vs_minsteps (container, container->tmpmin->steps);
	else
		world_vs_minsteps (container, container->tmpa->steps + \
		container->tmpmin->steps);
}
