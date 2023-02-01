/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:58:03 by mbennani          #+#    #+#             */
/*   Updated: 2023/02/01 13:18:55 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	prt;
	int		returned;

	va_start (prt, format);
	returned = 0;
	while (*format && returned > -1)
	{	
		if ((flag_getter(format) > 0 && flag_getter(format) < 9) \
		&& returned > -1)
		{
			ft_printarg(flag_getter(format), prt, &returned);
			format += 2;
		}
		else if (flag_getter(format) == 9)
			format++;
		else if (*format)
		{
			ft_putchar(*format, 1, &returned);
			format++;
		}
	}
	va_end(prt);
	return (returned);
}

int	ft_printerr(const char *format, ...)
{
	va_list	prt;
	int		returned;

	va_start (prt, format);
	returned = 0;
	while (*format && returned > -1)
	{	
		if ((flag_getter(format) > 0 && flag_getter(format) < 9) \
		&& returned > -1)
		{
			ft_printargerr(flag_getter(format), prt, &returned);
			format += 2;
		}
		else if (flag_getter(format) == 9)
			format++;
		else if (*format)
		{
			ft_putchar(*format, 2, &returned);
			format++;
		}
	}
	va_end(prt);
	return (returned);
}
