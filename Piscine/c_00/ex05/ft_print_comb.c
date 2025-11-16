/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:38:50 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	digit_one;
	char	digit_two;
	char	digit_three;

	digit_one = '0';
	while (digit_one <= '7')
	{
		digit_two = digit_one + 1;
		while (digit_two <= '8')
		{
			digit_three = digit_two + 1;
			while (digit_three <= '9')
			{
				ft_print(digit_one, digit_two, digit_three);
				digit_three++;
			}
			digit_two++;
		}
		digit_one++;
	}
}
