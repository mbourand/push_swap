/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:32:51 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/09 00:24:20 by mbourand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#define TRUE 1
#define FALSE 0

#define BUFF_SIZE 24

#include <stdlib.h>

void		errndie(char *str);
size_t		ft_strlen(char *str);
void		ft_putstr(char *str, int fd);
int			is_integer(char *str);
int			ft_atoi(char *str, int *success);
void		ft_bzero(void *ptr, size_t size);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlcpy(char *s1, char *s2, size_t len);

#endif
