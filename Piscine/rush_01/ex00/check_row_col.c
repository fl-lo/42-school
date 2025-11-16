/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:11:35 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 20:11:42 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	indexer(char i, char reverse)
{
	if (reverse)
		return (3 - i);
	return (i);
}

char	check_column(char *board, char column, char reverse)
{
	char	result;
	char	i;
	char	max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[column + 4 * indexer(i, reverse)])
		{
			result++;
			max = board[column + 4 * indexer(i, reverse)];
		}
		i++;
	}
	return (result);
}

char	check_line(char *board, char line, char reverse)
{
	char	result;
	char	i;
	char	max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[line * 4 + indexer(i, reverse)])
		{
			result++;
			max = board[line * 4 + indexer(i, reverse)];
		}
		i++;
	}
	return (result);
}
