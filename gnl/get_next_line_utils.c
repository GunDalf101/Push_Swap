/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:04:25 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/28 19:27:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nline(t_list *buffer)
{
	int		i;
	t_list	*curr;

	if (!buffer)
		return (0);
	curr = ft_lstlastelem(buffer);
	i = 0;
	while (curr->content[i])
	{
		if (curr->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlastelem(t_list *buffer)
{
	t_list	*last;

	last = buffer;
	if (!last)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	line_alloc(char **line, t_list *buffer)
{
	int	i;
	int	len;

	len = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->content[i])
		{
			if (buffer->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		buffer = buffer->next;
	}
	*line = malloc(len * sizeof(char) + 1);
}

void	buff_free(t_list *buffer)
{
	t_list	*current;
	t_list	*next;

	current = buffer;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlength(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
