/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:28:07 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	dict_check(t_dict *dict, int nb_elements)
{
	int	i;

	i = 0;
	while (i < nb_elements)
	{
		if (!(is_alpha(dict[i].str)))
			return (0);
		if (!(is_numeric(dict[i].number)))
			return (0);
		i++;
	}
	return (1);
}
