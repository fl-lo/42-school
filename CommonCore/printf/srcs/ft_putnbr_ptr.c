/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:57:10 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long n, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, count);
	count++;
	write(1, &base[n % 16], 1);
	return (count);
}

int	ft_putnbr_ptr(void *ptr)
{
	unsigned long	tmp;
	int				count;

	tmp = (unsigned long)ptr;
	count = 0;
	if (tmp == 0)
	{
		write(1, "(nil)", 5);
		count += 3;
	}
	else
	{
		write(1, "0x", 2);
		count += ft_puthex(tmp, count);
	}
	return (count + 2);
}
