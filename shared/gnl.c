/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:00:04 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/09 00:28:57 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "utils.h"

static int	newline(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	int			bytes;
	static char	buffer[BUFFER_SIZE + 1];

	if (!line)
		return (-1);
	if (BUFFER_SIZE == 0)
	{
		*line = 0;
		return (-1);
	}
	*line = gnldupuntil("", 0);
	while (newline(buffer) == -1)
	{
		if (!(*line = gnljoinuntil(*line, buffer, '\n')))
			return (-1);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0 || !buffer[0])
			return (!buffer[0] ? 0 : bytes);
	}
	if (!(*line = gnljoinuntil(*line, buffer, '\n')))
		return (-1);
	ft_strlcpy(buffer, buffer + newline(buffer) + 1, BUFFER_SIZE);
	return (1);
}
