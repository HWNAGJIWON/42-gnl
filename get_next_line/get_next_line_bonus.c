/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:59:37 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/06/07 13:41:50 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_findnull(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*answer;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(answer = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		answer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		answer[i + j] = s2[j];
		j++;
	}
	answer[i + j] = 0;
	return (answer);
}

char	*ft_sort_line(char *backup, char **line, int r)
{
	int		i;
	char	*temp;

	i = ft_findnull(backup);
	if (i < ft_strlen(backup))
	{
		*line = ft_substr(backup, 0, i);
		temp = ft_substr(backup, i + 1, ft_strlen(backup));
		free(backup);
		backup = ft_strdup(temp);
		free(temp);
	}
	else if (r == 0)
	{
		*line = backup;
		backup = NULL;
	}
	return (backup);
}

char	*ft_update_backup(char *backup, char *buffer)
{
	char	*temp;

	if (backup)
	{
		temp = ft_strjoin(backup, buffer);
		free(backup);
		backup = ft_strdup(temp);
		free(temp);
	}
	else
		backup = ft_strdup(buffer);
	return (backup);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[255];
	char		buffer[BUFFER_SIZE + 1];
	int			r;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buffer, BUFFER_SIZE)))
	{
		if (r == -1)
			return (-1);
		buffer[r] = 0;
		backup[fd] = ft_update_backup(backup[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (r <= 0 && !backup[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	backup[fd] = ft_sort_line(backup[fd], line, r);
	if (r <= 0 && !backup[fd])
		return (r);
	return (1);
}
