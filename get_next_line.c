/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:50:52 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 14:33:13 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chek(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*return_free(char *buf)
{
	free(buf);
	return ((void *)0);
}

char	*ft_read(int fd)
{
	char	*buf;
	char	*str;
	int		ret;

	if (fd < 0)
		return ((void *)0);
	ret = 1;
	str = ft_calloc(1, 1);
	while (ret > 0 && chek(str))
	{
		buf = ft_calloc(1, BUFFER_SIZE + 1);
		ret = (int)read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin_free(str, buf, 0);
		if (ret < 0 || buf == (void *)0 || str == (void *)0)
		{
			str = return_free(str);
			return (buf = return_free(buf));
		}
		free(buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buf;
	static char	*res[4096];

	if (fd < 0 || fd > 4095)
		return ((void *)0);
	if (res[fd] && chek(res[fd]))
		buf = ft_strjoin_free(res[fd], ft_read(fd), 1);
	else if (res[fd] && *res[fd] != '\0')
		buf = res[fd];
	else
		buf = ft_read(fd);
	if (buf == (void *)0)
		return (buf);
	if (*buf == '\0')
		return (return_free(buf));
	res[fd] = ft_calloc(1, 1);
	str = ft_strdup_n(buf);
	if (!res[fd] || !str)
		return ((void *)0);
	res[fd] = ft_strjoin_free(res[fd], &buf[ft_strlen(str)], 0);
	if (*res[fd] == '\0')
		res[fd] = return_free(res[fd]);
	buf = return_free(buf);
	return (str);
}
