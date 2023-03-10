/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:06:41 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 17:11:04 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_cdlist
{
	int				pos;
	int				steps;
	int				content;
	struct s_cdlist	*next;
	struct s_cdlist	*prev;
}	t_cdlist;

size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *str, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nitems, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
char		*ft_itoa(int n);
char		**ft_split(char *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
t_cdlist	*ft_lstnew(int content);
void		ft_lstadd_front(t_cdlist **lst, t_cdlist *new);
int			ft_lstsize(t_cdlist *lst);
t_cdlist	*ft_lstlast(t_cdlist *lst);
void		ft_lstadd_back(t_cdlist **lst, t_cdlist *new);
void		ft_lstdelone(t_cdlist *lst);
void		ft_lstclear(t_cdlist **lst);
void		ft_lstiter(t_cdlist *lst, void (*f)(int));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_cdlist	*ft_lstmap(t_cdlist *lst, int (*f)(int));

#endif