/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:40:23 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "ft_writes.h"
#include "ft_string.h"
#include <stdlib.h>

char	*get_number_from_dict(char *nb, t_dict *d);

int	write_hundreds(char *numbers, t_dict *d)
{
	char	tmp[4];
	char	*str_from_dict;

	ft_strcpy(tmp, numbers);
	tmp[1] = '\0';
	str_from_dict = get_number_from_dict(tmp, d);
	if (str_from_dict)
	{
		ft_putstr(str_from_dict);
		ft_putstr(" ");
	}
	str_from_dict = get_number_from_dict("100", d);
	if (str_from_dict)
	{
		ft_putstr(str_from_dict);
		ft_putstr(" ");
	}
	else
		return (-1);
	return (1);
}

int	write_thousands(int index, t_dict *d)
{
	char	*cmp;
	int		i;

	if (index <= 0)
		return (0);
	cmp = malloc(sizeof(char) * (3 * index + 2));
	if (!cmp)
		return (0);
	i = 1;
	cmp[0] = '1';
	append_zeros(cmp, 3 * index);
	cmp[3 * index + 1] = '\0';
	i = 0;
	while (d[i].number)
	{
		if (!(ft_strcmp(d[i].number, cmp)))
		{
			write_spaces(d[i].str);
			free(cmp);
			return (1);
		}
		i++;
	}
	free(cmp);
	return (-1);
}

int	write_tens(char *numbers, t_dict *d)
{
	char	tmp[4];
	char	*str_from_dict;
	int		i;

	i = 0;
	tmp[0] = '\0';
	while (numbers[i + 1])
	{
		tmp[i] = numbers[i + 1];
		i++;
	}
	tmp[i - 1] = '0';
	tmp[i] = '\0';
	str_from_dict = get_number_from_dict(tmp, d);
	if (str_from_dict)
	{
		if (tmp[0] == '0')
			return (1);
		ft_putstr(str_from_dict);
		ft_putstr(" ");
	}
	else
		return (-1);
	return (1);
}

int	write_specials(char *numbers, char *tmp, t_dict *d)
{
	int		nbr_len;
	char	*str_from_dict;

	nbr_len = ft_strlen(numbers) - 1;
	while (nbr_len >= 0)
	{
		tmp[nbr_len] = '0';
		str_from_dict = get_number_from_dict(tmp, d);
		if (str_from_dict)
		{
			ft_putstr(str_from_dict);
			str_from_dict = get_number_from_dict(&numbers[nbr_len], d);
			if (str_from_dict && numbers[nbr_len] != '0')
			{
				ft_putstr(" ");
				ft_putstr(str_from_dict);
				if (nbr_len == 2)
					return (2);
			}
			return (1);
		}
		nbr_len--;
	}
	return (1);
}

int	write_units(char *numbers, t_dict *d)
{
	char	tmp[4];
	int		nbr_len;
	char	*str_from_dict;

	ft_strcpy(tmp, numbers);
	nbr_len = ft_strlen(numbers) - 1;
	tmp[0] = numbers[nbr_len];
	tmp[1] = '\0';
	str_from_dict = get_number_from_dict(tmp, d);
	if (str_from_dict)
	{
		if (nbr_len == 1)
			return (1);
		ft_putstr(str_from_dict);
	}
	else
		return (-1);
	return (1);
}
