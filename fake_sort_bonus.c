/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:49:59 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 21:00:09 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ops_comparator(t_cdlist **stack_a, t_cdlist **stack_b, char *op)
{
	if (ft_strncmp(op, "rra\n", 4) == 0)
		fake_rra(stack_a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		fake_rrb(stack_b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		fake_ra(stack_a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		fake_rb(stack_b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		fake_rr(stack_a, stack_b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		fake_rrr(stack_a, stack_b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		fake_pa(stack_b, stack_a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		fake_pb(stack_a, stack_b);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		fake_sa(stack_a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		fake_sb(stack_b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		fake_ss(stack_a, stack_b);
	else
		return (free(op), ft_printerr("Error\n"), exit(1));
}

void	get_ops(t_cdlist **stack_a, t_cdlist **stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op > 0)
	{
		ops_comparator(stack_a, stack_b, op);
		free(op);
		op = get_next_line(0);
	}
}
