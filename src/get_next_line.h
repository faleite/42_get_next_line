/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:50:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/23 21:34:01 by faaraujo         ###   ########.fr       */
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
#  define BUFFER_SIZE 100
# endif /* BUFFER_SIZE */

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

#endif /* GET_NEXT_LINE_H */
