/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/03 02:52:42 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_mover(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			minsteps;
	t_cdlist	*tmpb;
	t_cdlist	*tmpa;
	t_cdlist	*minb;
	t_cdlist	*mina;

	tmpb = *stack_b;
	tmpa = *stack_a;
	minb = tmpb;
	mina = tmpa;
	minsteps = INT32_MAX;
	while (tmpa)
	{
		tmpb = *stack_b;
		while (tmpb)
		{
			if (absolute(tmpa->content - tmpb->content) < absolute(tmpa->content - minb->content))
				minb = tmpb;
			tmpb = tmpb->next;
		}
		// printf("number == %d || moves == %d \n",tmpa->content,tmpa->steps + minb->steps);
		if (tmpa->steps + minb->steps < minsteps - 1)
		{
			minsteps = tmpa->steps + minb->steps;
			mina = tmpa;
		}
		tmpa = tmpa->next;
	}
	//rotate stack a
	if (mina->pos <= ft_lstsize(*stack_a) / 2)
	{
		while(mina->prev)
			ra(stack_a);
	}
	else if (mina->pos > ft_lstsize(*stack_a) / 2)
	{
		while(mina->prev)
			rra(stack_a);
	}
	//rotate stack b
	if (minb->pos <= ft_lstsize(*stack_b) / 2)
	{
		if (minb->content > mina->content)
		{
			while(minb->next)
				rb(stack_b);
		}
		else if (minb->content < mina->content)
		{
			while(minb->prev)
				rb(stack_b);
		}
	}
	else if (minb->pos > ft_lstsize(*stack_b) / 2)
	{
		if (minb->content > mina->content)
		{
			while(minb->next)
				rrb(stack_b);
		}
		else if (minb->content < mina->content)
		{
			while(minb->prev)
				rrb(stack_b);
		}
	}
}

void	the_path_finder(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist	*tmp;
	int			pos;

	tmp = *stack_a;
	pos = 0;
	while(tmp)
	{
		if (pos <= ft_lstsize(*stack_a) / 2)
			tmp->steps = pos;
		else if (pos > ft_lstsize(*stack_a) / 2)
			tmp->steps = ft_lstsize(*stack_a) - pos;
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	pos = 0;
	while(tmp)
	{
		if (pos <= ft_lstsize(*stack_b) / 2)
			tmp->steps = pos;
		else if (pos > ft_lstsize(*stack_b) / 2)
			tmp->steps = ft_lstsize(*stack_b) - pos;
		tmp->pos = pos;
		pos++;
		// printf ("tempa->%d\n", tmp->steps);
		tmp = tmp->next;
	}
	best_mover(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist *tmp;

	tmp = *stack_a;
	if ((*stack_a)->content < (*stack_a)->next->content)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while(ft_lstsize(*stack_a) > 3)
		the_path_finder(stack_a, stack_b);
}