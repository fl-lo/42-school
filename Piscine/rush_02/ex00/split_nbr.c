/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:47:07 by nredouan          #+#    #+#             */
/*   Updated: 2025/09/21 19:42:57 by fgargot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "free_array.h"

char	*ft_str3cpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

void	write_arr(int i, char **arr, char *str, int size)
{
	if (i == 0)
		arr[i] = ft_str3cpy(arr[i], str, (size % 3));
	else if ((size % 3) == 0)
		arr[i] = ft_str3cpy(arr[i], &str[3 * i], 0);
	else
		arr[i] = ft_str3cpy(arr[i], &str[3 * (i - 1) + (size % 3)], 0);
}

char	**split_nbr(char *str, int size)
{
	int		i;
	int		group;
	char	**arr;

	i = 0;
	group = (size + 2) / 3;
	arr = malloc((group + 1) * sizeof(char *));
	if (!arr)
	{
		free_array(arr);
		return (0);
	}
	while (i < group)
	{
		arr[i] = malloc(4 * sizeof(char));
		if (!arr[i])
		{
			free_array(arr);
			return (0);
		}
		write_arr(i, arr, str, size);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
