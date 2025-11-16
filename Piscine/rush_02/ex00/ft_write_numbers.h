/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_numbers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebigre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:51:47 by rlebigre          #+#    #+#             */
/*   Updated: 2025/09/21 19:58:36 by rlebigre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITE_NUMBERS_H
# define FT_WRITE_NUMBERS_H

# include "dictionary.h"

int		get_array_size(char **array);
char	*get_number_from_dict(char *nb, t_dict *d);
int		check_unique(char *tmp, t_dict *d);
int		write_by_hundreds(char *numbers, t_dict *d);
int		write_number(char **array, t_dict *d);

#endif
