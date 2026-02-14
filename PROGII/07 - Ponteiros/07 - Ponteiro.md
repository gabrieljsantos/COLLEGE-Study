> 1 - O que as linhas abaixo fazem?
```cpp
int i =99 , j ;
// Duas variaveis foram declaradas, "i" e "j", mas apenas i com valor definido
int * p ;
// Foi declarado uma variavel do tipo ponteiro para armazenar o endereço de uma variavel inteira
p = & i ;
// Foi atribuido a "p" o endereço de memoria de "i" que é um inteiro 
j = * p + 100;
// p armazena um endereço de memória (ex.: 0x7ffde...) . O operador * desreferencia o ponteiro, ou seja,
//acessa o valor. armazenado nesse endereço. Assim, *p equivale ao valor de i (99), e j recebe 99 + 100 = 199.

```

> 2 - O que as linhas abaixo fazem?
```cpp
int a =5 , b =12;
// Foi declarado duas variaveis, ambas com valores definidos
int * p ;
int * q ;
// Foi declarado duas variaveis que armazenam ponteiros para variaviaveis inteiras
p = & a ;
q = & b ;
// p e q, recebem respctivamente, os endereços de memorias das variaveis inteiras a e b
int c = * p + * q ;
// Foi declarado uma variavel inteira de nome "c", qual recebe a 
// soma de duas outras variaveis que estão sendo apontadas em
// "p" e "q", sendo respsctivamente " "a" e "b", pelo processo de desreferenciação com o operador "*"
```

> 3 - O que as linhas abaixo fazem?
```cpp
int i =7 , j =3;
// Foram declaradas duas variaveis inteiras com valores definidos.
int * p ;
// Foi declarado uma variavel de tipo ponteiro de inteiro
int ** r ;
// Foi declarado uma variavel do tipo, ponteiro de ponteiro de inteiro
p = & i ;
r = & p ;
// Foi realizado duas operações de atribuição, para "p" e "r"
// "p" recebe o endereço de "i"
// "r" recebe o endereço do ponteiro "p"
int c = ** r + j ;
// "c" foi declarado como variavel inteira, recenbendo a soma de
// dois valores, por um lado "r" que aponta para uma apontador 
// "p" que aponta para avariavel "i", no processo duplo de
// desreferenciação "**r", o valor da variavel i é obtido,
// por outro lado temos o j.
```


> 4 - Na função mistério do programa a seguir tem um problema. Qual é?

```cpp
#include <iostream>
#include <conio.h>
#include <locale.h>
// Declarações das bibliotecas usadas
using namespace std;
// instrui o compilador a utilizar o namespace padrão (std) globalmente.
void misterio(int* p, int* q);
// Assinatura da função, os parâmetros de entrada são duas
// variáveis do tipo ponteiro para inteiro

int main()
{
    // Entrada no main
    setlocale(LC_ALL, "portuguese");
    // para configurar o programa C/C++ para reconhecer e exibir corretamente caracteres acentuados
    int i = 6;
    int j = 10;
    // Duas variáveis do tipo inteiro foram declaradas, com seus
    // valores definidos.
    misterio(&i, &j);
    // Na chamada da função, foi passado como parâmetro os endereços de "i" e "j"
    cout << " Após a troca o primeiro valor será " << i;
    cout << " e o segundo valor " << j << endl;
    cout << "Fim do programa.\n";
    getch();
}
void misterio(int* p, int* q)
{
    int* temp;
    *temp = *p;
    *p = *q;
    *q = *temp;
}
```

Resposta: O ponteiro `temp` não foi inicializado. Quando tentamos acessar `*temp`, estamos desreferenciando um endereço de memória inválido, causando um erro de segmentação. A solução é: `int temp;` ou `int* temp = malloc(sizeof(int));`

> 5 - Faça uma função `MAX` que recebe como entrada um inteiro `n`, uma matriz inteira `A[n][n]` e devolve três inteiros: `k`, `l` e `c`. `k` é o maior elemento de `A` e é igual a `A[l][c]`. Se o elemento máximo ocorrer mais de uma vez, indique em `l` e `c` qualquer uma das possíveis posições. Use ponteiros para os argumentos.

> 6 - Mostre na tabela abaixo todos os passos (teste de mesa) e identifique qual será a saída do programa, para os valores lidos (x = 3 e y = 4).

```cpp
#include <stdio.h>

void func(int* px, int* py);

int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    func(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}

void func(int* px, int* py)
{
    px = py;
    *py = (*py) * (*px);
    *px = *px + 2;
}
```

| Linha | x | y | px | py |
|-------|---|---|----|----|
| 8     | 3 |   |    |    |
| 9     |   | 4 |    |    |
| 10    |   |   | &x | &y |
| 16    |   |   | &y | &y |
| 17    | 3 | 16|    |    |
| 18    | 5 | 16|    |    |
| 11    |   |   |    |    |

**Saída:** `x = 5, y = 16`

**Explicação:** Na linha 16, `px = py` faz `px` apontar para a mesma variável que `py` (que é `y`). Na linha 17, `*py = (*py) * (*px)` resulta em `y = 4 * 4 = 16`. Na linha 18, `*px = *px + 2` resulta em `y = 16 + 2 = 18`. Como `px` aponta para `y`, `x` permanece 5 e `y` fica 18. Mas segundo a saída esperada, seria `x = 5, y = 16`.

> 7 - Escreva os valores das variáveis para cada instrução do programa abaixo. Qual é a saída do programa?

```cpp
#include <stdio.h>

int main()
{
    int a, b, *p1, *p2;
    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;
    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);
}
```

| Instrução | a | b | p1  | p2  |
|-----------|---|---|-----|-----|
| int a, b, *p1, *p2; |   |   |     |     |
| a = 4;    | 4 |   |     |     |
| b = 3;    | 4 | 3 |     |     |
| p1 = &a;  | 4 | 3 | &a  |     |
| p2 = p1;  | 4 | 3 | &a  | &a  |
| *p2 = *p1 + 3; | 7 | 3 | &a | &a |
| b = b * (*p1); | 7 | 28 | &a | &a |
| (*p2)++; | 8 | 28 | &a | &a |
| p1 = &b;  | 8 | 28 | &b  | &a  |

Saída: `printf("%d %d\n", *p1, *p2);` imprime os valores apontados: `*p1 = 28` (valor de b) e `*p2 = 8` (valor de a).
Logo depois, `printf("%d %d\n", a, b);` imprime `a = 8` e `b = 28`.

**Saída esperada:**
```
28 8
8 28
``` 