# Function Open

*A chamada da funcao open() abre o arquivo especificado por **pathname**. Se o arquivo especificado não existir, ele pode opcionalmente (se **O_CREAT** for especificado em sinalizadores) ser criado por open().*

```c
 #include <fcntl.h>

       int open(const char *pathname, int flags);
       int open(const char *pathname, int flags, mode_t mode);

```

## Parâmetros 
-   **`pathname`** é uma string que representa o caminho para o arquivo que será aberto ou criado.
-   **`flags`** especifica as opções de abertura do arquivo, como leitura, escrita, criação, entre outras. Essas opções são definidas como macros, como:
    - **`O_RDONLY`** para abertura apenas leitura.
    - **`O_WRONLY`** para abertura apenas escrita.
    - **`O_RDWR`** para abertura leitura/escrita. 
- Além disso, outras opções podem ser combinadas usando operações de bit a bit, como:
	- **`O_CREAT`** para criar o arquivo se ele não existir ou
	- **`O_APPEND`** para escrever no final do arquivo.
-   **`mode`** é usado somente quando um novo arquivo é criado e especifica as permissões de acesso para o novo arquivo. As permissões são representadas por macros, como **`S_IRUSR`** para permissões de leitura para o usuário (dono do arquivo).

## Return
- A função **`open()`** retorna um *file descriptor* inteiro, que é um identificador único para o arquivo aberto. Esse descritor de arquivo pode ser usado posteriormente em outras chamadas de função para ler, escrever ou manipular o arquivo aberto.

## close()
- *É importante lembrar de fechar o arquivo usando a função **`close()`** quando você terminar de usá-lo, para liberar os recursos do sistema operacional associados ao arquivo aberto.*
