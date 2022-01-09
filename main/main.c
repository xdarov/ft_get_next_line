/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:33:30 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 14:59:10 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*s;
	char	*s2;

	fd1 = open("txt1", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	s = (char *)malloc(1);
	s2 = (char *)malloc(1);
	while (s || s2)
	{
		free(s);
		free(s2);
		if ((s = get_next_line(fd1)))
			printf("fd1: %s", s);
		if ((s2 = get_next_line(fd2)))
			printf("fd2: %s", s2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
