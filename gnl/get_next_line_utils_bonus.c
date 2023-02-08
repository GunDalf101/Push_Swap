/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:04:25 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/28 19:27:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// size_t	ft_strlength(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	while (*str != '\0' && *str != (unsigned char)c)
// 		str++;
// 	if (*str == (unsigned char)c)
// 		return ((char *)str);
// 	return (0);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*join;
// 	size_t	i;

// 	join = malloc(sizeof(char) * (ft_strlength(s1) + ft_strlength(s2) + 1));
// 	if (join == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (*s1 != '\0')
// 	{
// 		join[i] = *s1++;
// 		i++;
// 	}
// 	while (*s2 != '\0')
// 	{
// 		join[i] = *s2++;
// 		i++;
// 	}
// 	join[i] = '\0';
// 	return (join);
// }

// size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
// {
// 	size_t	src_len;
// 	size_t	i;

// 	src_len = ft_strlength(src);
// 	if (destsize)
// 	{
// 		i = 0;
// 		while (src[i] != '\0' && i < (destsize - 1))
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	return (src_len);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	char	*dup;

// 	i = 0;
// 	dup = malloc(sizeof(char *) * (ft_strlength(s) + 1));
// 	if (dup == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }
