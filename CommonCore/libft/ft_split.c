/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:53:43 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut_word(char const *s, char c)
{
	int		len;
	char	*out;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*free_arrays(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	res_c;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res_c = 0;
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	while (*s && res_c < word_count)
	{
		while (*s == c)
			s++;
		res[res_c] = cut_word(s, c);
		if (!res[res_c])
			return (free_arrays(res));
		s += ft_strlen(res[res_c]);
		res_c++;
	}
	res[res_c] = NULL;
	return (res);
}
