/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:40:48 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_totallen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_joinstrs(int size, char **strs, char *sep, char *out)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			out[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (i < size - 1 && sep[j])
		{
			out[k++] = sep[j];
			j++;
		}
		i++;
	}
	out[k] = '\0';
	return (out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;

	if (size <= 0)
	{
		out = malloc(1);
		out[0] = '\0';
		return (out);
	}
	out = malloc(ft_totallen(size, strs, sep) + 1);
	if (!out)
		return (NULL);
	return (ft_joinstrs(size, strs, sep, out));
}
