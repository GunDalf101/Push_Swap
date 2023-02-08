/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:00:55 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 19:38:25 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	fake_sa(t_cdlist **stack_a);
void	fake_ra(t_cdlist **stack_a);
void	fake_rra(t_cdlist **stack_a);
void	fake_sb(t_cdlist **stack_b);
void	fake_rb(t_cdlist **stack_b);
void	fake_rrb(t_cdlist **stack_b);
void	fake_ss(t_cdlist **stack_a, t_cdlist **stack_b);
void	fake_rr(t_cdlist **stack_a, t_cdlist **stack_b);
void	fake_rrr(t_cdlist **stack_a, t_cdlist **stack_b);
void	fake_pb(t_cdlist **stack_b, t_cdlist **stack_a);
void	fake_pa(t_cdlist **stack_b, t_cdlist **stack_a);
int		xstrncmp(char *av);
void	dup_detector(t_cdlist **stack_a);
void	get_ops(t_cdlist **stack_a, t_cdlist **stack_b);

#endif