/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgargot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:58:59 by fgargot           #+#    #+#             */
/*   Updated: 2025/09/21 14:01:06 by fgargot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "ft_string.h"
#include "ft_writes.h"
#include <stdlib.h>
#include <unistd.h>

int	get_array_size(char **array)
{
	int	result;

	result = 0;
	while (array[result])
		result++;
	return (result);
}

char	*get_number_from_dict(char *nb, t_dict *d)
{
	int	i;

	i = 0;
	while (d[i].number)
	{
		if (!ft_strcmp(nb, d[i].number))
			return (d[i].str);
		i++;
	}
	return (0);
}

int	check_unique(char *tmp, t_dict *d)
{
	char	*str_from_dict;

	str_from_dict = get_number_from_dict(tmp, d);
	if (str_from_dict)
	{
		ft_putstr(str_from_dict);
		return (1);
	}
	else
		return (0);
}

int	write_by_hundreds(char *numbers, t_dict *d)
{
	int		special;
	char	tmp[4];
	int		nbr_len;
	int		res;

	nbr_len = ft_strlen(numbers) - 1;
	ft_strcpy(tmp, numbers);
	res = check_unique(tmp, d);
	if (res == 1)
		return (1);
	special = write_specials(numbers, tmp, d);
	if (nbr_len == 2 && special != 2)
		res = write_hundreds(numbers, d);
	if (res == -1)
		return (-1);
	if (special != 2)
		res = write_tens(numbers, d);
	if (res == -1)
		return (-1);
	if (special != 2 && res != 2)
		res = write_units(numbers, d);
	if (res == -1)
		return (-1);
	return (1);
}

int	write_number(char **array, t_dict *d)
{
	int	size;
	int	i;
	int	err;

	size = get_array_size(array);
	i = 0;
	while (i < size)
	{
		err = write_by_hundreds(array[i], d);
		if (err < 1)
			return (err);
		if (i < size - 1)
		{
			err = write_thousands(size - i - 1, d);
			if (err < 1)
				return (err);
		}
		i++;
	}
	return (1);
}
