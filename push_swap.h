/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:34:28 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/08 19:38:15 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_helper
{
	t_cdlist	*tmpb;
	t_cdlist	*tmpa;
	t_cdlist	*tmpmin;
	t_cdlist	*minb;
	t_cdlist	*mina;
	int			sizea;
	int			sizeb;
	int			minsteps;
}				t_helper;

void			sa(t_cdlist **stack_a);
void			ra(t_cdlist **stack_a);
void			rra(t_cdlist **stack_a);
void			sb(t_cdlist **stack_b);
void			rb(t_cdlist **stack_b);
void			rrb(t_cdlist **stack_b);
void			ss(t_cdlist **stack_a, t_cdlist **stack_b);
void			rr(t_cdlist **stack_a, t_cdlist **stack_b);
void			rrr(t_cdlist **stack_a, t_cdlist **stack_b);
void			pb(t_cdlist **stack_b, t_cdlist **stack_a);
void			pa(t_cdlist **stack_b, t_cdlist **stack_a);
int				xstrncmp(char *av);
void			sort_checker(t_cdlist **stack_a);
void			sort_stack(t_cdlist **stack_a, t_cdlist **stack_b);
int				minimus(t_cdlist *stack);
void			sort_stack(t_cdlist **stack_a, t_cdlist **stack_b);
int				absolute(int num);
void			three_lsort(t_cdlist **stack_a);
void			fake_rra(t_cdlist **stack_a);
void			fake_ra(t_cdlist **stack_a);
void			fake_rrb(t_cdlist **stack_a);
void			fake_rb(t_cdlist **stack_a);
t_cdlist		*minimus2_0(t_cdlist *stack);
t_cdlist		*maxima(t_cdlist *stack);
void			pos_updater(t_cdlist **stack);
void			rr_rrr_mover(t_cdlist **stack_a, \
					t_cdlist **stack_b, \
					t_helper *container);
void			ra_rra_mover(t_cdlist **stack_a, t_helper *container);
void			rb_rrb_mover(t_cdlist **stack_b, t_helper *container);
void			world_vs_minsteps(t_helper *container, int comparer);
void			super_sort(t_cdlist **stack_b, t_cdlist **stack_a);
void			min_locker(t_helper *container);
void			b_iterator(t_helper *container, t_cdlist **stack_b);
void			twofacesort(t_cdlist **stack_a);
void			sa_rra_or(t_cdlist **stack_a, int which);

#endif