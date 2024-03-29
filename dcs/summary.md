# Summary

## Descricao
- Este projeto trata da programação de uma função que retorna uma linha lida de um descritor de arquivo.

## Novo
- [static_variable](./static_variable.md)
- [read](./read)
- [file_descriptor](./file_descriptor)
- [EOF (End of File)](./EOF.md)

## Requisitos
Function name | get_next_line
-------------|--------------
Prototype | char \*get_next_line(int fd);
Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h 
Parameters | fd: The file descriptor to read from
Return value | Read line: correct behavior 
Return value | NULL: there is nothing else to read, or an error occurred
External functs. | read, malloc, free
Description | Write a function that returns a line read from a file descriptor 

- Chamadas repetidas (por exemplo, usando um loop) para sua função get_next_line() devem permitir que você leia o arquivo de texto apontado pelo descritor de arquivo, **uma linha por vez.**
- Sua função deve retornar a linha que foi lida
  - Se não houver mais nada para ler ou se ocorreu um erro, ele deve retornar NULL
- Certifique-se de que sua função funcione conforme o esperado ao ler um arquivo e ao ler a partir da entrada padrão.
- **Observe** que a linha retornada deve incluir o caractere final \\n, exceto se o final do arquivo for alcançado e não terminar com um caractere \\n.
- Seu arquivo de cabeçalho get_next_line.h deve conter pelo menos o protótipo da função get_next_line().
- Adicione todas as funções auxiliares necessárias no arquivo get_next_line_utils.c
- Como você terá que ler arquivos em get_next_line(), adicione esta opção à sua chamada do compilador: `-D BUFFER_SIZE=n` 
  - Definirá o tamanho do buffer para read().
  - O valor do tamanho do buffer será modificado por seus pares avaliadores e pela Moulinette para testar seu código.
  
***Devemos ser capazes de compilar este projeto com e sem o sinalizador -D BUFFER_SIZE além dos sinalizadores usuais. Você pode escolher o valor padrão de sua escolha.***

- Você compilará seu código da seguinte maneira (um tamanho de buffer de 42 é usado como exemplo):
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
- Consideramos que get_next_line() tem comportamento indefinido se o arquivo apontado pelo descritor de arquivo mudou desde a última chamada enquanto read() não chegou ao final do arquivo.
- Também consideramos que get_next_line() tem um comportamento indefinido ao ler um arquivo binário. No entanto, você pode implementar uma maneira lógica de lidar com esse comportamento, se desejar.

 ***Sua função ainda funciona se o valor de BUFFER_SIZE for 9999? Se for 1? 10000000? Você sabe por quê?***

>R: O código funcionará normalmente independentemente do valor de `BUFFER_SIZE`, mas o comportamento exato dependerá do tamanho do arquivo de entrada e da quantidade de dados disponíveis para leitura.
>
 > - Por exemplo, se você definir `BUFFER_SIZE` como 9999 e o arquivo de entrada tiver menos de 9999 bytes, a função `read` lerá todos os bytes disponíveis e armazenará na string `s`. Se o arquivo tiver mais de 9999 bytes, a função `read` lerá apenas os primeiros 9999 bytes.

***Tente ler o mínimo possível cada vez que get_next_line() for chamado. Se você encontrar uma nova linha, deverá retornar a linha atual.
					Não leia o arquivo inteiro e depois processe cada linha.***

### Proibido
- Você não tem permissão para usar sua libft neste projeto.
- lseek() é proibido.
- Variáveis globais são proibidas.
---
## Referencias
- [Master File I/O Operations with 42’s get_next_line Project | by A. Yigit Ogun | Medium](https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5)
- https://velog.io/@ljiwoo59/getnextline
- https://hector.dev.br/2021/08/27/GNL-get-next-line-42/
- https://soulee.dev/2023/01/02/42-seoul-get-next-line
- https://valuelog.tistory.com/122
