# Function Read

*A função **`read()`** é usada para ler dados de um arquivo ou de um descritor de arquivo em sistemas operacionais baseados em UNIX.*

*Sua declaração é a seguinte:*

```c
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t nbytes);
```

*Os parâmetros da função são:*

-   **`fd`**: O descritor de arquivo do qual deseja-se ler os dados. O descritor de arquivo é um inteiro que identifica o arquivo aberto ou outro dispositivo de entrada/saída. Em geral, o descritor de arquivo é obtido por meio da função `open()` ou é um descritor padrão pré definido, como 0 para entrada padrão (stdin).
-   **`buffer`**: Um ponteiro para o buffer onde os dados lidos serão armazenados. Essa área de memória deve ser suficientemente grande para conter os dados lidos.
-   **`nbytes`** ou **`count`**: O número máximo de bytes a serem lidos do arquivo.

*O valor de retorno da função **`read()`** é um tipo especial chamado **`ssize_t`**, que representa um número de bytes lidos.* 

*O valor de retorno pode ser interpretado da seguinte forma:*
- **Um valor maior que 0** indica que a leitura foi bem-sucedida e retorna o número de bytes lidos.
- **0** indica que o final do arquivo foi alcançado.
- **-1** indica que ocorreu um erro durante a leitura. Nesse caso, a variável global **`errno`** é definida com um código de erro específico que pode ser consultado usando funções como **`perror()`**  ou **`strerror()`** para obter uma descrição do erro.

*A função **read()** tentará ler até **nbytes** do arquivo ou até encontrar o final do arquivo. Se a função for interrompida por um sinal antes de ler qualquer byte, ela retornará imediatamente com um valor menor que **nbytes**. A função **read()** pode ser bloqueante, o que significa que, se não houver dados disponíveis para leitura, ela poderá pausar a execução do programa até que haja dados disponíveis.*

A função **read()** é usada principalmente para ler dados brutos de arquivos ou dispositivos de entrada/saída de baixo nível, como sockets ou pipes. É importante realizar manipulações adequadas de erros e garantir que o buffer fornecido seja grande o suficiente para acomodar os dados lidos.