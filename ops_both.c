/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:03:19 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/03 19:39:48 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_cdlist **stack_a, t_cdlist **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	rr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	fake_ra(stack_a);
	fake_rb(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	fake_rra(stack_a);
	fake_rrb(stack_b);
	ft_printf("rrr\n");
}