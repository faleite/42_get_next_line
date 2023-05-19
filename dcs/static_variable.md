# Static Variable

*Variável estática é uma variável que mantém seu valor entre diferentes chamadas de uma função ou durante a execução de um programa. Elas são declaradas usando a palavra-chave **static** antes do tipo de dados da variável.*

*Existem duas formas principais de uso de variáveis estáticas em C:*

1. *Variáveis estáticas locais*: Quando uma variável estática é declarada  dentro de uma função, ela mantém seu valor entre chamadas sucessivas à função. Isso significa que a variável é inicializada apenas uma vez, na primeira vez em que a função é chamada, e mantém seu valor nas chamadas subsequentes. 
*Por exemplo:*
```c
#include <stdio.h>

void contador() {
    static int count = 0;  // Variável estática local
    
    count++;
    printf("Contagem: %d\n", count);
}

int main() {
    contador();  // printf -> Contagem: 1
    contador();  // printf -> Contagem: 2
    contador();  // printf -> Contagem: 3
   
/* Se a variavel "count" nao fosse estatica as tres
* chamadas da funcao sempre retornariam:
* printf -> Contagem: 1
* printf -> Contagem: 1
* printf -> Contagem: 1 */
    
    return 0;
}
```
  - No exemplo acima, a variável `count` é declarada como estática dentro da função `contador()`. A cada chamada da função, o valor de `count` é  incrementado e exibido na tela. Como a variável é  estática, ela mantém seu valor entre as chamadas e não é  redeclarada ou reinicializada. 

2.  *Variáveis estáticas globais*: Quando uma variável estática é declarada fora de qualquer função, ela é chamada de variável estática global. Essa variável é acessível em todo o escopo do arquivo e mantém seu valor durante toda a execução do programa. 
*Por exemplo:*
```c
#include <stdio.h>

static int counter = 0;  // Variável estática global

void incrementar() {
    counter++;
}

int main() {
    incrementar();
    incrementar();
    incrementar();
    
    printf("Valor do contador: %d\n", counter);  // Valor do contador: 3
    
    return 0;
}
```
  - Nesse caso, a variável `counter` é uma variável estática global. A função `incrementar()` incrementa seu valor a  cada chamada e, no final do programa, o valor final de  `counter` é exibido.