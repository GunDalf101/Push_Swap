/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:31:19 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/01 17:53:59 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_getter(const char *format)
{
	if (*format == '%' && *(format + 1) == 'c')
		return (1);
	else if (*format == '%' && *(format + 1) == 's')
		return (2);
	else if (*format == '%' && *(format + 1) == 'p')
		return (3);
	else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		return (4);
	else if (*format == '%' && *(format + 1) == 'u')
		return (5);
	else if (*format == '%' && *(format + 1) == 'x')
		return (6);
	else if (*format == '%' && *(format + 1) == 'X')
		return (7);
	else if (*format == '%' && *(format + 1) == '%')
		return (8);
	else if (*format == '%')
		return (9);
	return (0);
}
