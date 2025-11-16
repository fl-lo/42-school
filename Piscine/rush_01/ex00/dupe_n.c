/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupe_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:58:44 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 19:59:11 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_dupe(unsigned int *dupe, char c, char l, char s)
{
	if ((*dupe & (1 << (c - 1)) && c != 0)
		|| (*dupe & (1 << (l + s - 1)) && l != 0))
		return (1);
	if (c != 0)
		*dupe |= 1 << (c - 1);
	if (l != 0)
		*dupe |= 1 << (l + s - 1);
	return (0);
}

char	check_dupes_n(char *board, char index, char s)
{
	unsigned int	dupe;
	int				i;

	i = 0;
	dupe = 0;
	while (i < s)
	{
		if (check_dupe(&dupe, board[i * s + (index % s)],
				board[i + (index / s) * s], s))
			return (1);
		i++;
	}
	return (0);
}
