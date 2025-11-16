/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:18:12 by rlebigre          #+#    #+#             */
/*   Updated: 2025/09/21 12:42:41 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "free_array.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].number)
	{
		free(dict[i].number);
		free(dict[i].str);
		i++;
	}
	free(dict);
}
