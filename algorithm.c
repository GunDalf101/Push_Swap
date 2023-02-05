/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 01:05:35 by mbennani         ###   ########.fr       */
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
	int			sizea = ft_lstsize(*stack_a);
	int			sizeb = ft_lstsize(*stack_b);

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
		if (tmpa->pos <= sizea / 2 && minb->pos <= sizeb / 2)
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
			else if (tmpa->pos <= minb->pos)
			{
				if (minb->steps < minsteps)
				{
					minsteps = minb->steps;
					minbbb = minb;
					mina = tmpa;
				}
			}
		}
		else if (tmpa->pos > sizea / 2 && minb->pos > sizeb / 2)
		{
			if ((sizea - tmpa->pos) >= (sizeb - minb->pos))
			{
				if (tmpa->steps < minsteps)
				{
					minsteps = tmpa->steps;
					minbbb = minb;
					mina = tmpa;
				}
				
			}
			else if ((sizea - tmpa->pos) < (sizeb - minb->pos))
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
	if (mina->pos <= sizea / 2 && minbbb->pos <= sizeb / 2)
	{
		while (mina->prev && minbbb->prev)
			rr(stack_a, stack_b);
	}
	else if (mina->pos > sizea / 2 && minbbb->pos > sizeb / 2)
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
	if (mina->pos <= sizea / 2)
	{
		while(mina->prev)
			ra(stack_a);
	}
	else if (mina->pos > sizea / 2)
	{
		while(mina->prev)
			rra(stack_a);
	}
	//rotate stack b
	if (minbbb->pos <= sizeb / 2)
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
	else if (minbbb->pos > sizeb / 2)
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
	int			sizea = ft_lstsize(*stack_a);
	int			sizeb = ft_lstsize(*stack_b);

	tmp = *stack_a;
	pos = 0;
	while(tmp)
	{
		if (pos <= sizea / 2)
			tmp->steps = pos;
		else if (pos > sizea / 2)
			tmp->steps = sizea - pos;
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	pos = 0;
	while(tmp)
	{
		if (pos <= sizeb / 2)
			tmp->steps = pos;
		else if (pos > sizeb / 2)
			tmp->steps = sizeb - pos;
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
	int			sizea = ft_lstsize(*stack_a);
	int			sizeb = ft_lstsize(*stack_b);

	max = maxima(*stack_b);
	// max_pos = max->pos;
	if (max->pos <= sizeb / 2)
	{
		while (max->prev)
			rb(stack_b);
	}
	else if ((max->pos > sizeb / 2))
	{
		while (max->prev)
			rrb(stack_b);
	}
}

void	super_sort(t_cdlist **stack_b, t_cdlist **stack_a)
{
	// kola mrra trotati twli takhod lprev
	t_cdlist	*thelast = ft_lstlast(*stack_a);
	t_cdlist	*max = maxima(*stack_a);
	while (thelast->content > (*stack_b)->content && max->next)
	{
		thelast = thelast->prev;
		rra(stack_a);
	}
	pa(stack_b, stack_a);
}

void	five_lsort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	int			sizea = ft_lstsize(*stack_a);
	t_cdlist	*tmp;
	t_cdlist	*minim;
	int pos;
	int i = 0;

	while (i < 22)
	{
		minim = minimus2_0(*stack_a);
		while (minim->prev)
		{
			if (minim->pos <= sizea / 2)
				ra(stack_a);
			else if ((minim->pos > sizea / 2))
				rra(stack_a);
		}
	sizea--;
	pb(stack_a, stack_b);
	tmp = *stack_a;
	pos = 0;
	while(tmp)
	{
		if (pos <= sizea / 2)
			tmp->steps = pos;
		else if (pos > sizea / 2)
			tmp->steps = sizea - pos;
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	i++;
	}
	
	three_lsort(stack_a);
	i = 0;
	while (i< 22){
	pa(stack_b, stack_a);
	i++;
	}
}

void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist	*tmp;
	int			pos;
	t_cdlist	*max = maxima(*stack_a);

	tmp = *stack_a;
	if ((*stack_a)->content < (*stack_a)->next->content)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while(ft_lstsize(*stack_a) > 25)
		the_path_finder(stack_a, stack_b);
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
	stack_b_rotater(stack_b, stack_a);
	five_lsort(stack_a, stack_b);
	if (ft_lstlast(*stack_a)->content > (*stack_b)->content)
		rra(stack_a);
	while(ft_lstsize(*stack_b))
		super_sort(stack_b, stack_a);
	while (max->next)
		rra(stack_a);
}