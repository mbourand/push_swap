/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:59:30 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/12 14:59:43 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
size_t	gnllenuntil(const char *s, char c);
char	*gnldupuntil(const char *s1, char c);
char	*gnljoinuntil(char *s1, char const *s2, char c);

#endif
