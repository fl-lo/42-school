/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:46:29 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_rules(char *board, char *rules, char index);
char	print_board(char *board, char size);

char	solve_board(char *board, char *rules)
{
	int		i;
	char	tab_size;

	tab_size = 16;
	i = 0;
	while (i < tab_size)
	{
		if (i < 0)
			return (0);
		board[i] += 1;
		if (board[i] == 5)
		{
			board[i] = 0;
			i -= 1;
			continue ;
		}
		if (check_rules(board, rules, i))
			i++;
	}
	return (1);
}
