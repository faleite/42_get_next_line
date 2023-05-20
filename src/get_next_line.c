/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 18:16:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char *s;

    s = (char *)malloc(sizeof(char)* BUFFER_SIZE);
    if (!s)
        return (NULL);
    read(fd, s, BUFFER_SIZE);
    /* COLOCAR CARACTER NULO NO FINAL DA STRING*/
    return(s);
}


int main(void)
{
    int fd;
    char *s;

    fd = open("test.txt", 0, O_RDWR);
    
    s = get_next_line(fd);

    printf("%d\n", fd);
    printf("\n%s", s);
    free(s);
    return (0);
}
