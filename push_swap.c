/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:34:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 21:45:37 by mbennani         ###   ########.fr       */
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
			return (ft_printerr("Error: duplicate detected!!"), exit(1));
		compared = compared->next;
	}
}

void	make_list(t_cdlist **stack_a, char **arg)
{
	t_cdlist	*node;
	char		*nums;
	char		**nums2;
	int			i;

	i = 0;
	nums = ft_strdup("");
	while (arg[++i])
	{
		nums = ft_strjoin(nums, arg[i]);
		if (ft_strncmp(arg[i], "", 1) == 0 || xstrncmp(arg[i]) == 0)
			return (ft_printerr("Error: Empty argument found!!"), exit(1));
		nums = ft_strjoin(nums, " ");
	}
	nums2 = ft_split(nums, ' ');
	i = -1;
	while (nums2[++i])
	{
		node = ft_lstnew(ft_atoi(nums2[i]));
		ft_lstadd_back(stack_a, node);
	}
	dup_detector(stack_a);
}

void	twofacesort(t_cdlist **stack_a)
{
	t_cdlist	*node;

	node = *stack_a;
	if (ft_lstsize(*stack_a) == 2 && node->content > node->next->content)
		ra(stack_a);	
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
		if(node->content > nodext->content && nodext->content > nodext2->content)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if (nodext->content > nodext2->content && nodext2->content > node->content)
		{
			rra(stack_a);
			sa(stack_a);
		}
		else if (node->content > nodext2->content && nodext2->content > nodext->content)
			ra(stack_a);
		else if (nodext2->content > node->content && node->content > nodext->content)
			sa(stack_a);
		else if (nodext->content > node->content && node->content > nodext2->content)
			rra(stack_a);
	}
}

int	main(int ac, char **av)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	t_cdlist	*node;

	if (ac > 1)
	{
		make_list(&stack_a, av);
		sort_checker(&stack_a);
		// twofacesort(&stack_a);
		// three_lsort(&stack_a);
		sort_stack(&stack_a, &stack_b);
		node = stack_a;
		while (node)
		{
			ft_printf("data -> %d\n", node->content);
			node = node->next;
		}
		ft_printf("\n");
		node = ft_lstlast(stack_a);
		while (node)
		{
			ft_printf("data -> %d\n", node->content);
			node = node->prev;
		}
		ft_printf("\n");
		node = stack_b;
		while (node)
		{
			ft_printf("data -> %d\n", node->content);
			node = node->next;
		}
		ft_printf("\n");
		node = ft_lstlast(stack_b);
		while (node)
		{
			ft_printf("data -> %d\n", node->content);
			node = node->prev;
		}
	}
	return (0);
}
