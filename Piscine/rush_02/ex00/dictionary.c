/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgargot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:10:32 by fgargot           #+#    #+#             */
/*   Updated: 2025/09/21 20:34:19 by fgargot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "ft_string.h"
#include "ft_split_str.h"
#include "free_array.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	count_sep(char *str, char c)
{
	int	count;
	int	is_new_sub;
	int	i;

	count = 0;
	i = 0;
	is_new_sub = 1;
	while (str[i])
	{
		if (is_new_sub && str[i] != c)
			count++;
		is_new_sub = (str[i] == c);
		i++;
	}
	return (count);
}

int	write_dict2(int i, int s, char **split_s, t_dict **dict)
{
	char	*tmp;

	ft_strncpy((*dict)[i].number, split_s[i], s);
	while (split_s[i][s] && split_s[i][s] != ':')
		s++;
	tmp = &split_s[i][s + 1];
	s = 0;
	while (tmp[s])
		s++;
	(*dict)[i].str = malloc(sizeof(char) * (s + 1));
	if ((*dict)[i].str == 0)
	{
		free((*dict)[i].number);
		free_dict(*dict);
		return (0);
	}
	ft_strcpy((*dict)[i].str, tmp);
	return (1);
}

int	write_dict(int i, char **split_s, t_dict **dict)
{
	int	s;
	int	j;

	s = 0;
	while (split_s[i][s] && split_s[i][s] != ':' && split_s[i][s] != ' ')
		s++;
	(*dict)[i].number = malloc(sizeof(char) * (s + 1));
	if ((*dict)[i].number == 0)
	{
		free_dict(*dict);
		return (0);
	}
	j = 0;
	while (j < s + 1)
	{
		(*dict)[i].number[j] = '\0';
		j++;
	}
	if (split_s[i][s] != '\0')
		if (!write_dict2(i, s, split_s, dict))
			return (0);
	return (1);
}

int	build_dict(t_dict **dict, char **split_s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (split_s[count])
		count++;
	*dict = malloc(sizeof(t_dict) * (count + 1));
	if (!(*dict))
		return (0);
	while (split_s[i])
	{
		if (!write_dict(i, split_s, dict))
			return (0);
		i++;
	}
	(*dict)[i].number = 0;
	(*dict)[i].str = 0;
	return (1);
}

// Reads dictionary data from the file specified by filepath
// and stored in a t_dict array referenced by dict
// Returns 1 on success, -1 on dictionaty access error, 0 on other error
int	get_dictionary_from_file(t_dict **dict, char *filepath)
{
	char				buffer[10000];
	int					fd;
	int					len;
	char				**split_str;
	unsigned int		i;

	i = 0;
	while (i < sizeof(buffer))
	{
		buffer[i] = '\0';
		i++;
	}
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = read(fd, buffer, sizeof(buffer));
	if (len == -1)
		return (-1);
	split_str = ft_split(buffer, '\n');
	if (!split_str)
		return (0);
	build_dict(dict, split_str);
	close(fd);
	free_array(split_str);
	return (1);
}
