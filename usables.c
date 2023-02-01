/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usables.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:10:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 19:39:06 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int xstrncmp(char *av)
{
	char	**spill;

	spill = ft_split(av, ' ');
	if (*spill == 0)
		return (0);
	return (1);
}

int	maxima(t_cdlist *stack)
{
	int	max;
	
	max = stack->content;
	while(stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	printf("the max is %d\n", max);
	return (max);
}

int	minimus(t_cdlist *stack)
{
	int	min;
	
	min = stack->content;
	while(stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	printf("the min is %d\n", min);
	return (min);
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
