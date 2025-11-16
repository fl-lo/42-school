/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:03:53 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	append_zeros(char *s, int len)
{
	int	i;

	i = 1;
	while (i <= len)
	{
		s[i] = '0';
		i++;
	}
}

void	write_spaces(char *str)
{
	ft_putstr(" ");
	ft_putstr(str);
	ft_putstr(" ");
}
