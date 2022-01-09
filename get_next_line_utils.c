/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:14:12 by pcorina           #+#    #+#             */
/*   Updated: 2021/11/02 14:14:18 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_n(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strdup_n(char *s1)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen_n(s1) + 2));
	if (!str)
		return ((void *)0);
	i = 0;
	while (*s1 && *s1 != '\n')
		str[i++] = *s1++;
	if (*s1 == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2, int chek)
{
	size_t	i;
	char	*str;
	char	*buf;
	char	*buf2;

	buf = s1;
	buf2 = s2;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return ((void *)0);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (chek)
		free(buf2);
	free(buf);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return ((void *)0);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
