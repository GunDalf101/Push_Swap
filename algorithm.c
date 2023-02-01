/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 21:55:02 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_mover(t_cdlist **stack_a, t_cdlist **stack_b, int sizeb)
{
	int			minsteps;
	t_cdlist	*tmpb;
	t_cdlist	*tmpa;
	t_cdlist	*min;

	tmpb = *stack_b;
	tmpa = *stack_a;
	min = tmpb;
	minsteps = INT32_MAX;
	while (tmpa)
	{
		while (tmpb)
		{
			if (absolute(tmpa->content - tmpb->content) < absolute(tmpa->content - min->content))
				min = tmpb;
			tmpb = tmpb->next;
		}
		if (tmpa->steps + min->steps < minsteps - 1)
			minsteps = tmpa->steps + min->steps + 1;
		tmpa = tmpa->next;
	}
		printf ("minsteps->%d\n", minsteps);
}

void	the_path_finder(t_cdlist **stack_a, t_cdlist **stack_b, int sizea, int sizeb)
{
	t_cdlist	*tmp;
	int			pos;

	tmp = *stack_a;
	pos = 1;
	while(tmp)
	{
		if (pos <= sizea / 2)
			tmp->steps = pos;
		else if (pos > sizea / 2)
			tmp->steps = sizea - pos;
		pos++;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	pos = 1;
	while(tmp)
	{
		if (pos <= sizeb / 2)
			tmp->steps = pos;
		else if (pos > sizeb / 2)
			tmp->steps = sizeb - pos;
		pos++;
		tmp = tmp->next;
	}
	best_mover(stack_a, stack_b, sizeb);
}

void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist *tmp;
	size_t	sizea;
	size_t	sizeb;
	
	sizea = ft_lstsize(*stack_a);
	sizeb = 2;
	tmp = *stack_a;
	if ((*stack_a)->content < (*stack_a)->next->content)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while(sizea >= 3)
	{
		the_path_finder(stack_a, stack_b, sizea, sizeb);
		sizea--;
		sizeb++;
	}
}