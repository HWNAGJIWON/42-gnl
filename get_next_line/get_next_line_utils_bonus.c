/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:00:01 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/07 13:14:43 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (str == NULL)
		return (0);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (len-- && str[i + start])
	{
		dest[i] = str[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*p;

	if (!(p = (void *)malloc(n * size)))
		return ((void *)0);
	i = 0;
	while (i < size)
	{
		*((char *)p + i) = 0;
		i++;
	}
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s[len])
		len++;
	ptr = ft_calloc(len + 1, 1);
	if (ptr == 0)
		return (0);
	len = 0;
	while (s[len])
	{
		ptr[len] = s[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (0 == c)
		return ((char *)&str[i]);
	return (0);
}
