/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:00:25 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 20:24:25 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			return (free(nums), ft_printerr("Error\n"), \
					exit(1));
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

void	sort_checker2(t_cdlist **stack_a, t_cdlist **stack_b)
{
	t_cdlist	*node;

	if (*stack_b)
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		ft_printf("KO\n");
		exit(0);
	}
	node = *stack_a;
	while (node->next)
	{
		if (node->content > node->next->content)
			return ((void)ft_printf("KO\n"));
		node = node->next;
	}
	ft_lstclear(stack_a);
	ft_printf("OK\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (ac > 1)
	{
		make_list(&stack_a, av);
		get_ops(&stack_a, &stack_b);
		sort_checker2(&stack_a, &stack_b);
	}
	return (0);
}
