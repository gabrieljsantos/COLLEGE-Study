>O que as linhas abaixo fazem?
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

>O que as linhas abaixo fazem?
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

>O que as linhas abaixo fazem?
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


> Na funcão misterio do programa a seguir tem um problema. Qual ´e?
```cpp
# include < iostream >
# include < conio .h >
# include < locale .h >
// Declarações da bibliotecas usadas
using namespace std ;
// instrui o compilador a utilizar o namespace padrão (std) globalmente.
void misterio (int *p , int * q ) ;
// Assinatura da função, os paramentros de entrada são duas
// variaveis do tipo ponteiro para inteiro

int main ()
{
    // Entrada no main
    setlocale ( LC_ALL ," portuguese ") ;
    // para configurar o programa C/C++ para reconhecer e exibir corretamente caracteres acentuados
    int i = 6;
    int j = 10;
    // Duas Variaveis do tipo inteiro forma declaradas, com seus
    // valores definidos.
    misterio (& i , & j ) ;
    // Na chamada da função, foi passado como parametro os endereços de "i" e "j"
    cout << " Após a troca o primeiro valor ser´a " << i ;
    cout << " e o segundo valor " << j << endl ;
    cout << "Fim do programa .\n";
    getch () ;
}
void misterio (int *p , int * q )
{
int * temp ;
* temp = * p ;
* p = * q ;
* q = * temp ;
}
```

