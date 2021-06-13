/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhwang <jiwhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:59:22 by jiwhwang          #+#    #+#             */
/*   Updated: 2021/05/28 20:01:32 by jiwhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *str, unsigned int m, size_t len);
int		ft_findnull(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t n, size_t size);
int		ft_strlen(const char *str);
char	*ft_update_backup(char *backup, char *buffer);
char	*ft_sort_line(char *backup, char **line, int r);
#endif
