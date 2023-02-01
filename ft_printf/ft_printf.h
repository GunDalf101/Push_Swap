/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:57:25 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 13:18:37 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		flag_getter(const char *format);
void	ft_putstr(char *s, int fd, int *returned);
void	ft_putnbr(int n, int fd, int *returned);
void	ft_putchar(char c, int fd, int *returned);
int		ft_atoi(const char *str);
void	ft_printarg(int flag, va_list ptr, int *returned);
void	ft_putunsigned_fd(unsigned int n, int fd, int *returned);
void	lowerhex(unsigned long int n, int *returned);
void	upperhex(unsigned long int n, int *returned);
void	ft_address(void *ptr, int *returned);
int		ft_printerr(const char *format, ...);
void	ft_printargerr(int flag, va_list ptr, int *returned);

#endif