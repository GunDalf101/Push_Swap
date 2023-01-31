/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:19:23 by mbennani          #+#    #+#             */
/*   Updated: 2023/01/31 01:52:38 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lowerhex(unsigned long int n, int *returned)
{
	if (n <= 15 && *returned != -1)
	{
		ft_putchar("0123456789abcdef"[n], 1, returned);
	}
	else if (n > 15)
	{
		lowerhex(n / 16, returned);
		lowerhex(n % 16, returned);
	}
}

void	upperhex(unsigned long int n, int *returned)
{
	if (n <= 15 && *returned != -1)
	{
		ft_putchar("0123456789ABCDEF"[n], 1, returned);
	}
	else if (n > 15)
	{
		upperhex(n / 16, returned);
		upperhex(n % 16, returned);
	}
}

void	ft_address(void *ptr, int *returned)
{
	ft_putstr("0x", 1, returned);
	lowerhex((unsigned long int)ptr, returned);
}
