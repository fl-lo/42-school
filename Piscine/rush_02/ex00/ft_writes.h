/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:50:08 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITES_H
# define FT_WRITES_H

# include "dictionary.h"

int		write_units(char *numbers, t_dict *d);
int		write_specials(char *numbers, char *tmp, t_dict *d);
int		write_tens(char *numbers, t_dict *d);
int		write_hundreds(char *numbers, t_dict *d);
void	append_zeros(char *s, int len);
int		write_thousands(int index, t_dict *d);
void	write_spaces(char *str);

#endif
