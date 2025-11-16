/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:58:34 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb, int count)
{
	if (nb > 9)
	{
		count += ft_putnbr_u(nb / 10, count);
		ft_putchar(48 + nb % 10);
	}
	else
		ft_putchar(nb + 48);
	count++;
	return (count);
}
