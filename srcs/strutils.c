/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:33:59 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:41:16 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

char		*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(res = malloc(sizeof(char) * s1_len + s2_len + 1)))
		return (NULL);
	while (i < s1_len)
		res[i] = s1[i];
	while (i < s1_len + s2_len)
		res[i] = s2[i - s1_len];
	res[i] = '\0';
	return (res);
}

size_t		ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (len);
}

int			ft_strcmp(char *s1, char *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (i < s1_len && i < s2_len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void		ft_putstr(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

size_t		ft_strlen(char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
