/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:04:33 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/28 19:27:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 10240
# endif

char	*get_next_line(int fd);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strdup(const char *s1);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
// size_t	ft_strlength(const char *s);

#endif