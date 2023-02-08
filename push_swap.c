/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:34:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 23:32:43 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_detector(t_cdlist **stack_a)
{
	int			count;
	t_cdlist	*compared;
	t_cdlist	*comparer;

	compared = *stack_a;
	while (compared)
	{
		comparer = *stack_a;
		count = 0;
		while (comparer)
		{
			if (comparer->content == compared->content)
				count++;
			comparer = comparer->next;
		}
		if (count >= 2)
			return (ft_lstclear(stack_a), \
			ft_printerr("Error\n"), exit(1));
		compared = compared->next;
	}
}

void	make_list(t_cdlist **stack_a, char **arg)
{
	t_cdlist	*node;
	char		**nums2;
	int			i;
	char		*nums;

	i = 0;
	nums = ft_strdup("");
	while (arg[++i])
	{
		nums = ft_strjoin(nums, arg[i]);
		if (ft_strncmp(arg[i], "", 1) == 0 || xstrncmp(arg[i]) == 0)
			return (free(nums), \
			ft_printerr("Error\n"), exit(1));
		nums = ft_strjoin(nums, " ");
	}
	nums2 = ft_split(nums, ' ');
	i = -1;
	while (nums2[++i])
	{
		node = ft_lstnew(ft_atoi(nums2[i]));
		ft_lstadd_back(stack_a, node);
		free(nums2[i]);
	}
	dup_detector(stack_a);
	return (free(nums2), free(nums));
}

void	twofacesort(t_cdlist **stack_a)
{
	t_cdlist	*node;

	node = *stack_a;
	if (ft_lstsize(*stack_a) == 2 && node->content > node->next->content)
		ra(stack_a);
	exit (0);
}

void	three_lsort(t_cdlist **stack_a)
{
	t_cdlist	*node;
	t_cdlist	*nodext;
	t_cdlist	*nodext2;

	node = *stack_a;
	nodext = node->next;
	nodext2 = nodext->next;
	if (ft_lstsize(*stack_a) == 3)
	{
		if (node->content > nodext->content && \
		nodext->content > nodext2->content)
			sa_rra_or (stack_a, 0);
		else if (nodext->content > nodext2->content && \
		nodext2->content > node->content)
			sa_rra_or (stack_a, 1);
		else if (node->content > nodext2->content && \
		nodext2->content > nodext->content)
			ra(stack_a);
		else if (nodext2->content > node->content && \
		node->content > nodext->content)
			sa(stack_a);
		else if (nodext->content > node->content && \
		node->content > nodext2->content)
			rra(stack_a);
	}
}

int	main(int ac, char **av)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (ac > 1)
	{
		make_list(&stack_a, av);
		sort_checker(&stack_a);
		if (ac == 3)
			twofacesort(&stack_a);
		if (ac == 4)
			return (three_lsort(&stack_a), 0);
		sort_stack(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	return (0);
}
