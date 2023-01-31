/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:34:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 00:00:19 by mbennani         ###   ########.fr       */
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
			return (ft_printf("Error: duplicate detected!!"), exit(1));
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
			return (ft_printf("Error: Empty argument found!!"), exit(1));
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

void	ac_handler(int ac,char **av, t_cdlist **stack_a)
{
	t_cdlist	*node;
	int			i;
	char		**arg;
	char		**ard;

	node = *stack_a;
	i = 0;
	arg = ft_split(av[1], ' ');
	ard = ft_split(av[2], ' ');
	while (arg[i])
		i++;
	if (i == 1 && !av[2])
		exit(0);
	else if (i == 1 && av[2] && av[3])
		return ;
	if (((i == 2 && !av[2]) || (i == 1 && !av[3] && ac == 3)) && node->content > node->next->content && (ard == NULL||ard[1] == NULL))
	{
		ra(stack_a);	
		exit (0);
	}
	else if (((i == 2 && !av[2]) || (i == 1 && !av[3] && ac == 3)) && (ard == NULL||ard[1] == NULL))
		exit (0);
}

int	main(int ac, char **av)
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	t_cdlist	*node;

	if (ac > 1)
	{
		make_list(&stack_a, av);
		ac_handler(ac, av, &stack_a);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pa(&stack_b, &stack_a);
		pa(&stack_b, &stack_a);
		pa(&stack_b, &stack_a);
		ra(&stack_a);
		ra(&stack_a);
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
