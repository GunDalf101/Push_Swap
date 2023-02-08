/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:04:29 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/28 19:27:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buff_add(t_list **buffer, char *buff, int red)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc((red + 1) * sizeof(char));
	if (!new->content)
		return ;
	i = 0;
	while (buff[i] && i < red)
	{
		new->content[i] = buff[i];
		i++;
	}
	new->content[i] = '\0';
	if (!*buffer)
	{
		*buffer = new;
		return ;
	}
	last = ft_lstlastelem(*buffer);
	last->next = new;
}

void	buff_read(int fd, t_list **buffer, int *redp)
{
	char	*buff;

	while (!find_nline(*buffer) && *redp != 0)
	{
		buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		*redp = (int)read(fd, buff, BUFFER_SIZE);
		if ((!*buffer && !*redp) || *redp == -1)
		{
			free(buff);
			return ;
		}
		buff[*redp] = '\0';
		buff_add(buffer, buff, *redp);
		free (buff);
	}
}

void	ext_line(t_list *buffer, char **line)
{
	int		i;
	int		j;

	if (!buffer)
		return ;
	line_alloc (line, buffer);
	if (!*line)
		return ;
	j = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->content[i])
		{
			if (buffer->content[i] == '\n')
			{
				(*line)[j++] = buffer->content[i];
				break ;
			}
			(*line)[j++] = buffer->content[i++];
		}
		buffer = buffer->next;
	}
	(*line)[j] = '\0';
}

void	buff_clear(t_list **buffer)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlastelem(*buffer);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(((ft_strlength(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return (free(clean_node));
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	buff_free(*buffer);
	*buffer = clean_node;
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;
	int				red;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	red = 1;
	buff_read (fd, &buffer, &red);
	if (!buffer)
		return (NULL);
	ext_line(buffer, &line);
	buff_clear(&buffer);
	if (line[0] == '\0')
	{
		buff_free(buffer);
		buffer = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
