/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgargot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:50:47 by fgargot           #+#    #+#             */
/*   Updated: 2025/09/21 12:04:01 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_str.h"
#include "free_array.h"
#include "ft_string.h"
#include "dictionary.h"
#include <stdlib.h>

int	iterate_split(char **result, char *str, int count)
{
	int	i;
	int	a;

	i = 0;
	while (i < count)
	{
		a = 0;
		while (str[a] && str[a] != '\n')
			a++;
		result[i] = malloc(sizeof(char) * (a + 1));
		if (!result[i])
		{
			free_array(result);
			return (0);
		}
		ft_strncpy(result[i], str, a);
		str = &str[a + 1];
		i++;
	}
	result[count] = 0;
	return (1);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		count;

	count = count_sep(str, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	if (!iterate_split(result, str, count))
		return (0);
	return (result);
}
