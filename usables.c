/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usables.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:10:14 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 21:46:05 by mbennani         ###   ########.fr       */
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