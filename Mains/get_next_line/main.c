/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahhhhh <nahhhhh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:54:04 by nahhhhh           #+#    #+#             */
/*   Updated: 2025/11/16 17:54:33 by nahhhhh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*ss;

	if (ac < 2)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	while ((ss = get_next_line(fd)) != NULL)
	{
		printf("%s", ss);
		free(ss);
	}
}