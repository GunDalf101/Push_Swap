/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:57:40 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/05 16:49:31 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printarg(int flag, va_list ptr, int *returned)
{
	if (flag == 1)
		ft_putchar(va_arg(ptr, int), 1, returned);
	else if (flag == 2)
		ft_putstr(va_arg(ptr, char *), 1, returned);
	else if (flag == 3)
		ft_address(va_arg(ptr, void *), returned);
	else if (flag == 4)
		ft_putnbr(va_arg(ptr, int), 1, returned);
	else if (flag == 5)
		ft_putunsigned_fd(va_arg(ptr, unsigned int), 1, returned);
	else if (flag == 6)
		lowerhex(va_arg(ptr, unsigned int), returned);
	else if (flag == 7)
		upperhex(va_arg(ptr, unsigned int), returned);
	else if (flag == 8)
		ft_putchar('%', 1, returned);
}

void	ft_printargerr(int flag, va_list ptr, int *returned)
{
	if (flag == 1)
		ft_putchar(va_arg(ptr, int), 2, returned);
	else if (flag == 2)
		ft_putstr(va_arg(ptr, char *), 2, returned);
	else if (flag == 3)
		ft_address(va_arg(ptr, void *), returned);
	else if (flag == 4)
		ft_putnbr(va_arg(ptr, int), 2, returned);
	else if (flag == 5)
		ft_putunsigned_fd(va_arg(ptr, unsigned int), 2, returned);
	else if (flag == 6)
		lowerhex(va_arg(ptr, unsigned int), returned);
	else if (flag == 7)
		upperhex(va_arg(ptr, unsigned int), returned);
	else if (flag == 8)
		ft_putchar('%', 2, returned);
}
