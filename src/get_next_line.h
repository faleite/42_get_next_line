/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:50:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/31 21:01:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /* for function read() */
# include <fcntl.h> /* for function open() */
# include <stdio.h> /* for standard input/output */
# include <stdlib.h> /* for funtions malloc() and free() */
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif /* BUFFER_SIZE */

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, char *s2);

int	del_line(char *s);

int    clean_line(char *buffer);

size_t	ft_strlen(char *s);

#endif /* GET_NEXT_LINE_H */
