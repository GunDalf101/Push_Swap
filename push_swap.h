/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:34:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/04 22:26:32 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	sa(t_cdlist **stack_a);
void	ra(t_cdlist **stack_a);
void	rra(t_cdlist **stack_a);
void	sb(t_cdlist **stack_b);
void	rb(t_cdlist **stack_b);
void	rrb(t_cdlist **stack_b);
void	ss(t_cdlist **stack_a, t_cdlist **stack_b);
void	rr(t_cdlist **stack_a, t_cdlist **stack_b);
void	rrr(t_cdlist **stack_a, t_cdlist **stack_b);
void	pb(t_cdlist **stack_b, t_cdlist **stack_a);
void	pa(t_cdlist **stack_b, t_cdlist **stack_a);
int		xstrncmp(char *av);
void	sort_checker(t_cdlist **stack_a);
void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b);
int		minimus(t_cdlist *stack);
void	sort_stack(t_cdlist **stack_a, t_cdlist **stack_b);
int		absolute(int num);
void	three_lsort(t_cdlist **stack_a);
void	fake_rra(t_cdlist **stack_a);
void	fake_ra(t_cdlist **stack_a);
void	fake_rrb(t_cdlist **stack_a);
void	fake_rb(t_cdlist **stack_a);
t_cdlist	*minimus2_0(t_cdlist *stack);
t_cdlist	*maxima(t_cdlist *stack);


#endif