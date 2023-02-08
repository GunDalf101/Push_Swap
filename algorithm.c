/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/07 21:07:21 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_mover(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_helper	*container;

	container = malloc(sizeof(t_helper));
	container->tmpb = *stack_b;
	container->tmpa = *stack_a;
	container->tmpmin = container->tmpb;
	container->mina = container->tmpa;
	container->minb = container->tmpmin;
	container->minsteps = INT32_MAX;
	container->sizea = ft_lstsize(*stack_a);
	container->sizeb = ft_lstsize(*stack_b);
	while (container->tmpa)
	{
		b_iterator(container, stack_b);
		min_locker(container);
		container->tmpa = container->tmpa->next;
	}
	rr_rrr_mover(stack_a, stack_b, container);
	ra_rra_mover(stack_a, container);
	rb_rrb_mover(stack_b, container);
	free(container);
}

void	the_path_finder(t_cdlist **stack_a, t_cdlist **stack_b)
{
	pos_updater(stack_a);
	pos_updater(stack_b);
	best_mover(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	stack_b_rotater(t_cdlist **stack_b, t_cdlist **stack_a)
{
	t_cdlist	*max;
	int			sizea;
	int			sizeb;

	sizea = ft_lstsize(*stack_a);
	sizeb = ft_lstsize(*stack_b);
	max = maxima(*stack_b);
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

void	sort_finalizer(t_cdlist **stack_a, t_cdlist **stack_b, int final_sizea)
{
	int			sizea;
	t_cdlist	*minim;
	int			i;

	sizea = ft_lstsize(*stack_a);
	while (sizea-- > 3)
	{
		minim = minimus2_0(*stack_a);
		while (minim->prev)
		{
			if (minim->pos <= sizea / 2)
				ra(stack_a);
			else if ((minim->pos > sizea / 2))
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		pos_updater(stack_a);
	}
	if (ft_lstsize(*stack_a) == 3)
		three_lsort(stack_a);
	else
		twofacesort(stack_a);
	i = -1;
	while (++i < final_sizea)
		pa(stack_b, stack_a);
}

void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist	*tmp;
	t_cdlist	*max;
	int			final_sizea;

	max = maxima(*stack_a);
	final_sizea = ft_lstsize(*stack_a) * 9 / 100 - 1;
	tmp = *stack_a;
	if ((*stack_a)->content < (*stack_a)->next->content)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (final_sizea < 0)
		final_sizea = 0;
	while (ft_lstsize(*stack_a) > final_sizea + 3)
		the_path_finder(stack_a, stack_b);
	pos_updater(stack_b);
	stack_b_rotater(stack_b, stack_a);
	sort_finalizer(stack_a, stack_b, final_sizea);
	if (ft_lstlast(*stack_a)->content > (*stack_b)->content)
		rra(stack_a);
	while (ft_lstsize(*stack_b))
		super_sort(stack_b, stack_a);
	while (max->next)
		rra(stack_a);
}
