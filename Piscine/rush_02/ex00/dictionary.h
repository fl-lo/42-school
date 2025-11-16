/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgargot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:05:34 by fgargot           #+#    #+#             */
/*   Updated: 2025/09/20 19:18:29 by fgargot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

typedef struct s_dict
{
	char	*number;
	char	*str;
}	t_dict;
int	get_dictionary_from_file(t_dict **dict, char *filepath);
int	count_sep(char *str, char c);

#endif
