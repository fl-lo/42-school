/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:17:48 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:36 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				count);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				count);
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'p')
		count += ft_putnbr_ptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *msg, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (msg == NULL)
		return (-1);
	va_start(args, msg);
	while (msg[i])
	{
		if (msg[i] == '%' && msg[i + 1])
		{
			count += ft_find_type(msg[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &msg[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}
