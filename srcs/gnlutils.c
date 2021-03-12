/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:01:27 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 15:08:20 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t		gnllenuntil(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		*gnldupuntil(const char *s1, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * (gnllenuntil(s1, '\n') + 1))))
		exit(1);
	while (s1[i] && s1[i] != c)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char		*gnljoinuntil(char *s1, char const *s2, char c)
{
	char	*res;
	int		i;
	int		s1_len;
	int		s2_len;

	if (!s1)
		return (gnldupuntil(s2, '\n'));
	if (!s2)
		return (0);
	s1_len = gnllenuntil(s1, 0);
	s2_len = 0;
	while (s2[s2_len] && s2[s2_len] != c)
		s2_len++;
	i = -1;
	if (!(res = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		exit(1);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i] && s2[i] != c)
		res[s1_len + i] = s2[i];
	res[s1_len + i] = 0;
	free(s1);
	return (res);
}
