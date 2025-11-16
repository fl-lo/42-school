/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:04:56 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"
#include "free_array.h"
#include "dictionary.h"
#include "split_nbr.h"
#include "clean_str.h" 
#include "dict_check.h"
#include "ft_write_numbers.h"

int	verify_input(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_strlen(argv[argc - 1]) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	write_error(int e, t_dict *dict, char **nbr_array)
{
	if (e == 0)
		write(2, "Error\n", 6);
	if (e == -1)
		write(2, "Dict Error\n", 11);
	free_dict(dict);
	free_array(nbr_array);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dictpath;
	char	*nbr;
	char	**nbr_array;
	t_dict	*dict;
	int		ctrl;

	if (!verify_input(argc, argv))
		return (1);
	nbr = argv[argc - 1];
	dictpath = "numbers.dict";
	if (argc == 3)
		dictpath = argv[1];
	nbr = clean_str(nbr);
	nbr_array = split_nbr(nbr, ft_strlen(nbr));
	ctrl = get_dictionary_from_file(&dict, dictpath);
	if (ctrl <= 0)
		return (write_error(ctrl, dict, nbr_array));
	ctrl = write_number(nbr_array, dict);
	if (ctrl <= 0)
		return (write_error(ctrl, dict, nbr_array));
	free_dict(dict);
	free_array(nbr_array);
	return (0);
}
