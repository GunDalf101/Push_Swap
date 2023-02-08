/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:36:32 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 19:27:41 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
