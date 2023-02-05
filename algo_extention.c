/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_extention.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:01:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 15:07:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rrr_norm(t_cdlist **stack_a, t_cdlist **stack_b, \
t_helper *container, int which)
{
	if (which == 0)
	{
		while (container->mina->prev && container->minb->next)
			rr(stack_a, stack_b);
	}
	else if (which == 1)
	{
		while (container->mina->prev && container->minb->next)
			rrr(stack_a, stack_b);
	}
}

void	rr_rrr_mover(t_cdlist **stack_a, t_cdlist **stack_b, \
t_helper *container)
{
	if (container->mina->pos <= container->sizea / 2 && container->minb->pos <= \
	container->sizeb / 2 && container->minb->content > container->mina->content)
		rr_rrr_norm(stack_a, stack_b, container, 0);
	else if (container->mina->pos <= container->sizea / 2 && \
	container->minb->pos <= container->sizeb / 2 && \
	container->minb->content < container->mina->content)
	{
		while (container->mina->prev && container->minb->prev)
			rr(stack_a, stack_b);
	}
	else if (container->mina->pos > container->sizea / 2 && \
	container->minb->pos > container->sizeb / 2 && \
	container->minb->content > container->mina->content)
		rr_rrr_norm(stack_a, stack_b, container, 1);
	else if (container->mina->pos > container->sizea / 2 && \
	container->minb->pos > container->sizeb / 2 && \
	container->minb->content < container->mina->content)
	{
		while (container->mina->prev && container->minb->prev)
			rrr(stack_a, stack_b);
	}
}

void	ra_rra_mover(t_cdlist **stack_a, t_cdlist **stack_b, \
t_helper *container)
{
	if (container->mina->pos <= container->sizea / 2)
	{
		while (container->mina->prev)
			ra(stack_a);
	}
	else if (container->mina->pos > container->sizea / 2)
	{
		while (container->mina->prev)
			rra(stack_a);
	}
}

void	rb_rrb_mover(t_cdlist **stack_a, t_cdlist **stack_b, \
t_helper *container)
{
	if (container->minb->pos <= container->sizeb / 2 && \
	container->minb->content > container->mina->content)
	{
		while (container->minb->next)
			rb(stack_b);
	}
	else if (container->minb->pos <= container->sizeb / 2 && \
	container->minb->content < container->mina->content)
	{
		while (container->minb->prev)
			rb(stack_b);
	}
	else if (container->minb->pos > container->sizeb / 2 && \
	container->minb->content > container->mina->content)
	{
		while (container->minb->next)
			rrb(stack_b);
	}
	else if (container->minb->content < container->mina->content)
	{
		while (container->minb->prev)
			rrb(stack_b);
	}
}

void	super_sort(t_cdlist **stack_b, t_cdlist **stack_a)
{
	t_cdlist	*thelast;
	t_cdlist	*max;

	thelast = ft_lstlast(*stack_a);
	max = maxima(*stack_a);
	while (thelast->content > (*stack_b)->content && max->next)
	{
		thelast = thelast->prev;
		rra(stack_a);
	}
	pa(stack_b, stack_a);
}
