/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbourand <mbourand@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/08 19:32:49 by mbourand		  #+#	#+#			 */
/*   Updated: 2021/03/09 00:22:28 by mbourand		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "utils.h"

void		errndie(char *str)
{
	ft_putstr(str, 2);
	exit(1);
}

void		ft_putstr(char *str, int fd)
{
	if (!str)
		return;
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

int			is_integer(char *str)
{
	size_t i;

	if (!str)
		return (FALSE);
	i = (str[0] == '+' || str[0] == '-');
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			ft_atoi(char *str, int *success)
{
	long long ret;
	int sign;
	size_t i;

	if (!success)
		return (0);
	if (!str || !is_integer(str))
		return (*success = FALSE);
	ret = 0;
	sign = str[0] == '-' ? -1 : 1;
	i = (str[0] == '+' || str[0] == '-');
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		if (ret * sign > INT_MAX || ret * sign < INT_MIN)
			return (*success = FALSE);
		i++;
	}
	*success = TRUE;
	return (ret * sign);
}

void		ft_bzero(void *ptr, size_t size)
{
	size_t i;
	unsigned char* cast = (unsigned char*)ptr;

	i = 0;
	while (i < size)
	{
		cast[i] = 0;
		i++;
	}
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return NULL;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(res = malloc(sizeof(char) * s1_len + s2_len + 1)))
		return NULL;
	while (i < s1_len)
		res[i] = s1[i];
	while (i < s1_len + s2_len)
		res[i] = s2[i - s1_len];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
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
