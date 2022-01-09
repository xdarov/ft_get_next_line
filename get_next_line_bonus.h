/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:14:15 by pcorina           #+#    #+#             */
/*   Updated: 2021/11/02 16:18:05 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2, int chek);
void	*ft_calloc(size_t count, size_t size);
char	*ft_read(int fd);
char	*ft_strdup_n(char *s1);
size_t	ft_strlen(const char *s);

#endif