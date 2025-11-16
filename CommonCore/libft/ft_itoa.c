/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:22:37 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
}

int	ft_nbr_len(long nb, int isneg)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	if (isneg)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	out = (char *)malloc(sizeof(char) * (ft_nbr_len(nb, n < 0) + 1));
	if (!out)
		return (NULL);
	i = 0;
	if (nb == 0)
		out[i++] = '0';
	while (nb > 0)
	{
		out[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		out[i++] = '-';
	out[i] = '\0';
	ft_reverse(out);
	return (out);
}
