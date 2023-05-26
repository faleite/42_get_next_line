/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/26 21:38:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * 1. Ler n_bytes (BUFFER_SIZE)
 * 
 * 2. Armazenar em uma variavel (stash) ate encontrar '\n'
 * 
 * 3. Ao encontrar a '\n' armazenar em uma variavel a linha
 * 
 * 4. limpar da (stash) a linha encontrada, deixando o que sobrou
 * 
 * 5. Retornar a linha encontrada
 * 
 * Obs: "Ao declarar a stash como static conseguimos manter a sobra
 * que foi linda alem da '\n'"
 */

/**
 * @brief Função que obtém um valor de uma entrada externa.
 */
char	*read_buff(int fd, char *line)
{
	char	*stash;
	int	ret_read;

	ret_read = 1;
	stash = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	while (ft_strchr(stash, '\n') == 0 && ret_read != 0)
	{
		/**
		 * @brief read() -> return:
		 * 0 ser for lido ate o final
		 * -1 se a leitura falhar
		 * Outros valores (Ex. 1), valores de bytes lidos
		 * */
		ret_read = read(fd, stash, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash[ret_read] = '\0';
		line = ft_strjoin(line, stash);
	}
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = read_buff(fd);
	return (line);
}

int	main(void)
{
	/* char	*line; */
	/* int		i; */
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	printf("%s\n", get_next_line(fd));
	/* printf("\nFile Descriptor: %d\n\n", fd); */
	/* i = 1; */
	/* while (i <= 5) */
	/* { */
		/* line = get_next_line(fd); */
		/* printf("line [%02d]: %s", i, line); */
		/* free(line); */
		/* i++; */
	/* } */
	/* printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE)); */
	close(fd);
	return (0);
}
