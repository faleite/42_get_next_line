# File descriptor

## Mais sobre o parametro `fd`

- Os dados do buffer são gravados no local especificado pelo descritor de arquivo fornecido. Esses dados podem ser gravados em um arquivo regular, em um dispositivo de terminal, em um socket de rede ou em qualquer outro dispositivo que possua um descritor de arquivo válido.

*Os descritores de arquivo 0, 1 e 2 têm significados específicos em sistemas baseados em UNIX:*

- **Descritor de arquivo 0**, também conhecido como **`STDIN_FILENO`**, é usado para entrada padrão. Por padrão, ele está associado ao dispositivo de entrada, como o teclado.
- **Descritor de arquivo 1**, também conhecido como **`STDOUT_FILENO`**, é usado para saída padrão. Por padrão, ele está associado ao dispositivo de saída, como o terminal, onde os dados são exibidos.
- **Descritor de arquivo 2**, também conhecido como **`STDERR_FILENO`**, é usado para saída de erro padrão. Por padrão, ele também está associado ao dispositivo de saída, como o terminal, mas é usado para exibir mensagens de erro.

*Dessa forma, quando você chama a função **`write()`** usando o descritor de arquivo 1 (**`STDOUT_FILENO`**), os dados são escritos no terminal, que é o dispositivo de saída padrão. Isso ocorre porque o descritor de arquivo 1 está associado ao terminal, e a função **`write()`** grava os dados nesse local.*

*Por exemplo, o seguinte código escreveria a mensagem "Olá, mundo!" no terminal usando a função **`write()`**:*

```c
#include <unistd.h>
#include <string.h>
int main()
{
	const char *mensagem = "Olá, mundo!\n";
	write(STDOUT_FILENO, mensagem, strlen(mensagem));
	return 0;
}
```

