/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/04 03:58:06 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_mover(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			minsteps;
	t_cdlist	*tmpb;
	t_cdlist	*tmpa;
	t_cdlist	*minb;
	t_cdlist	*minbbb;
	t_cdlist	*mina;

	tmpb = *stack_b;
	tmpa = *stack_a;
	minb = tmpb;
	mina = tmpa;
	minbbb = minb;
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
		if (tmpa->pos <= ft_lstsize(*stack_a) / 2 && minb->pos <= ft_lstsize(*stack_b) / 2)
		{
			if (tmpa->pos > minb->pos)
			{
				if (tmpa->steps < minsteps)
				{
					minsteps = tmpa->steps;
					minbbb = minb;
					mina = tmpa;
				}
				
			}
			else
			{
				if (minb->steps < minsteps)
				{
					minsteps = minb->steps;
					minbbb = minb;
					mina = tmpa;
				}
			}
		}
		else if (tmpa->pos > ft_lstsize(*stack_a) / 2 && minb->pos > ft_lstsize(*stack_b) / 2)
		{
			if ((ft_lstsize(*stack_a) - tmpa->pos) > (ft_lstsize(*stack_b) - minb->pos))
			{
				if (tmpa->steps < minsteps)
				{
					minsteps = tmpa->steps;
					minbbb = minb;
					mina = tmpa;
				}
				
			}
			else
			{
				if (minb->steps < minsteps)
				{
					minsteps = minb->steps;
					minbbb = minb;
					mina = tmpa;
				}
			}
		}
		else
		{
			if (tmpa->steps + minb->steps < minsteps)
			{
				minsteps = tmpa->steps + minb->steps;
				minbbb = minb;
				mina = tmpa;
			}
		}
		tmpa = tmpa->next;
	}
	// rr and rrr
	if (mina->pos <= ft_lstsize(*stack_a) / 2 && minbbb->pos <= ft_lstsize(*stack_b) / 2)
	{
		while (mina->prev && minbbb->prev)
			rr(stack_a, stack_b);
	}
	else if (mina->pos > ft_lstsize(*stack_a) / 2 && minbbb->pos > ft_lstsize(*stack_b) / 2)
	{
		if (minbbb->content > mina->content)
		{
			while (mina->prev && minbbb->next)
			rrr(stack_a, stack_b);
		}
		else if (minbbb->content < mina->content)
		{
			while (mina->prev && minbbb->prev)
			rrr(stack_a, stack_b);
		}
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
	if (minbbb->pos <= ft_lstsize(*stack_b) / 2)
	{
		if (minbbb->content > mina->content)
		{
			while(minbbb->next)
				rb(stack_b);
		}
		else if (minbbb->content < mina->content)
		{
			while(minbbb->prev)
				rb(stack_b);
		}
	}
	else if (minbbb->pos > ft_lstsize(*stack_b) / 2)
	{
		if (minbbb->content > mina->content)
		{
			while(minbbb->next)
				rrb(stack_b);
		}
		else if (minbbb->content < mina->content)
		{
			while(minbbb->prev)
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
		tmp = tmp->next;
	}
	best_mover(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	stack_b_rotater(t_cdlist **stack_b, t_cdlist **stack_a)
{
	t_cdlist	*max;

	max = maxima(*stack_b);
	if (max->pos <= ft_lstsize(*stack_b) / 2)
	{
		while (max->prev)
			rb(stack_b);
	}
	else if ((max->pos > ft_lstsize(*stack_b) / 2))
	{
		while (max->prev)
			rrb(stack_b);
	}
}

void	super_sort(t_cdlist **stack_b, t_cdlist **stack_a)
{
	static int	count;
	while (ft_lstlast(*stack_a)->content > (*stack_b)->content && count != 1)
	{
		rra(stack_a);
		if (minimus(*stack_a) > (*stack_b)->content)
			count = 1;
	}
	pa(stack_b, stack_a);
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
	three_lsort(stack_a);
	stack_b_rotater(stack_b, stack_a);
	while (ft_lstlast(*stack_a)->content > (*stack_b)->content)
		rra(stack_a);
	// printf("the last of us -> %d\n",ft_lstlast(*stack_a)->content);
	while(ft_lstsize(*stack_b))
	{	
		super_sort(stack_b, stack_a);
		// if (ft_lstsize(*stack_b) == 3)
		// 	return ;
	}
	while (maxima(*stack_a)->next)
		rra(stack_a);
}