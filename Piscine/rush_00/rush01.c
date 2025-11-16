/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:45:22 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	check_ints(int x, int y)
{
	int	maxint;

	maxint = 2147483647;
	if (x <= 0 || y <= 0 || x >= maxint || y >= maxint)
		return (0);
	return (1);
}

void	ft_headers(int col, int row, int x, int y)
{
	int	lastcol;

	lastcol = col == x - 1;
	if (col == 0 && row == 0)
		ft_putchar('/');
	else if ((x != 1 && y != 1) && (col == x - 1 && row == y - 1))
		ft_putchar('/');
	else if ((lastcol || col == 0) && (row == y - 1 || (lastcol && row == 0)))
		write(1, "\\", 2);
	else
		ft_putchar('*');
}

void	ft_rest(int col, int x)
{
	if (col == 0 || col == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	if (check_ints(x, y) != 1)
		return ;
	while (col < x)
	{
		if (row == 0 || row == y - 1)
			ft_headers(col, row, x, y);
		else
			ft_rest(col, x);
		if (col >= x - 1)
		{
			col = 0;
			row++;
			ft_putchar('\n');
		}
		else
			col++;
		if (row >= y)
			return ;
	}
}
