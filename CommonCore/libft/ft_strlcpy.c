/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:46:08 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			src_size;
	size_t			max_len;

	i = 0;
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (src_size >= size)
		max_len = size - 1;
	else
		max_len = src_size;
	while (i < max_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[max_len] = '\0';
	return (src_size);
}
