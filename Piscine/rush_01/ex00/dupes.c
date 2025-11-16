/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:23:53 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_dupes(char *board, int index)
{
	int		i;
	int		row;
	int		col;
	char	value;
	char	size;

	size = 4;
	row = index / size;
	col = index % size;
	i = 0;
	value = board[index];
	while (i < size)
	{
		if (i != col && (value != 0) && board[row * size + i] == value)
			return (1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i != row && (value != 0) && board[i * size + col] == value)
			return (1);
		i++;
	}
	return (0);
}
