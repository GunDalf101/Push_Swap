/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usables.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:10:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 16:43:41 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	xstrncmp(char *av)
{
	int		i;
	char	**spill;

	spill = ft_split(av, ' ');
	if (*spill == 0)
		return (free(spill), 0);
	i = 0;
	while (spill[i])
	{
		free(spill[i]);
		i++;
	}
	free(spill);
	return (1);
}

t_cdlist	*maxima(t_cdlist *stack)
{
	t_cdlist	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_cdlist	*minimus2_0(t_cdlist *stack)
{
	t_cdlist	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	minimus(t_cdlist *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
