/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:39:33 by qlefevre          #+#    #+#             */
/*   Updated: 2022/11/30 18:36:20 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/* get_next_line.c */
char	*get_next_line(int fd);
char	*get_new_line(char *mem_line);
void	get_rest(char *mem_line, char *buf);

/* get_next_line_utils.c */
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *mem_line, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);

#endif
