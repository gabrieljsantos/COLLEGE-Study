# Noções de Probabilidade

## Conceitos Básicos

* **Evento:** resultado ou conjunto de resultados de um experimento aleatório.
  Ex.: Ao lançar um dado, "sair número par" é um evento.

* **Espaço Amostral:** conjunto de todos os resultados possíveis de um experimento.
  Ex.: Ao lançar um dado, (S = {1,2,3,4,5,6}).

* **Probabilidade Clássica:**
  $$
  P(A) = \frac{\text{número de casos favoráveis}}{\text{número total de casos}}
  $$

* **  titulo
   $$P(A) \approx \lim_{x\to\infty} \frac{Dp+A_j+C+D+S}{R} + \frac{A_{mb}\times R_b}{R_r} +\frac{Fé+deus}{x} $$

$Dp$ = Dedicação pessoal.  
$A_j$ = Ajuda.
$C$ = Constancia.
$D$ = Dinheiro.
$S$ = Saude.
$R$ = Resultados imprevisíveis ou aleatoriedade
$x$ = Realidade



* **Probabilidade Frequencista:**
  $$
  P(A) \approx \frac{\text{número de vezes que A ocorre}}{\text{número total de experimentos}}
  $$

```cpp
#include <stdio.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STRING
} SampleType;

void probabilidade_frequencista(
    void* element,       // elemento buscado
    void* sample,        // vetor de amostras
    int sample_size,     // tamanho do vetor
    SampleType type,     // tipo da amostra
    double *probability  // resultado
){
    int count = 0;

    switch(type) {
        case TYPE_INT: {
            int target = *(int*)element;
            int* arr = (int*)sample;
            for (int i = 0; i < sample_size; i++) {
                if (arr[i] == target) count++;
            }
            break;
        }

        case TYPE_DOUBLE: {
            double target = *(double*)element;
            double* arr = (double*)sample;
            for (int i = 0; i < sample_size; i++) {
                if (arr[i] == target) count++;
            }
            break;
        }

        case TYPE_STRING: {
            char* target = (char*)element;
            char** arr = (char**)sample;
            for (int i = 0; i < sample_size; i++) {
                if (strcmp(arr[i], target) == 0) count++;
            }
            break;
        }

        default:
            *probability = -1.0;
            return;
    }

    *probability = (double)count / (double)sample_size;
}

````

# Explicação de Ponteiros e Conversões em C


## `void*`
É um **ponteiro genérico** que pode apontar para qualquer tipo de dado (`int`, `double`, `char`, etc.).  
Não pode ser desreferenciado diretamente, sendo necessário um *cast* para o tipo correto antes de acessar o valor.

Exemplo:
```c
void* p;
int x = 42;
p = &x;
int valor = *(int*)p;  // converte para int* e acessa o valor
````

---

## `*probability`

Se `probability` é declarado como `double*`, significa que é um **ponteiro para double**.
O `*probability` acessa o valor armazenado no endereço apontado, permitindo que a função altere a variável original passada pelo chamador.

Exemplo:

```c
double p;
probabilidade_frequencista(..., &p);  // p recebe valor dentro da função
```

---

## `*(int*)element`

* `(int*)element` → converte o ponteiro genérico `void*` para `int*`.
* `*(...)` → desreferencia e acessa o valor.

Exemplo:

```c
int x = 10;
void* e = &x;
int valor = *(int*)e;  // valor = 10
```

---

## `(int*)sample`

Transforma `sample` (que é `void*`) em `int*`, ou seja, um ponteiro para vetor de inteiros.
Assim é possível acessar o vetor normalmente (`arr[i]`).

---

## `int*`

É um **ponteiro para int**. Aponta para um inteiro ou para o início de um vetor de inteiros.

Exemplo:

```c
int v[3] = {1, 2, 3};
int* arr = v;
printf("%d", arr[1]); // imprime 2
```

---

## `int* arr = (int*)sample`

Cria um ponteiro `arr` que aponta para um vetor de inteiros, após converter `sample` para `int*`.

---

## `double* arr = (double*)sample`

Mesma ideia anterior, mas para vetor de `double`.

---

## `char*`

Um **ponteiro para char**, usado em C para representar **strings** (sequência de caracteres terminada por `\0`).

Exemplo:

```c
char* fruta = "uva";
printf("%s", fruta);
```

---

## `char**`

Um ponteiro para ponteiro de caracteres, normalmente usado como **vetor de strings**.

Exemplo:

```c
char* palavras[] = {"uva", "pera", "maca"};
char** arr = palavras; // arr[i] acessa cada string
```

---

## `(char**)sample`

Converte o `void* sample` em `char**`, permitindo manipular o valor como vetor de strings.

---

## Resumo

* `void*` → ponteiro genérico.
* `(tipo*)` → *cast* para um ponteiro de tipo específico.
* `*ptr` → acessa o valor armazenado no endereço.
* `char*` → string.
* `char**` → vetor de strings.
* `*probability` → usado para devolver resultado pela função.
---

* **Probabilidade Subjetiva:** medida baseada na crença ou julgamento pessoal sobre a ocorrência de um evento.



## Operações com Probabilidades

* **União:**
  $$
  P(A \cup B) = P(A) + P(B) - P(A \cap B)
  $$

* **Interseção:**
  $$
  P(A \cap B)
  $$



* **Complementar:**
  $$
  P(A^c) = 1 - P(A)
  $$

## Exemplo em C++: Probabilidade Clássica

```cpp
#include <iostream>

double classical_probability(int favorable, int total) {
    return static_cast<double>(favorable) / total;
}

int main() {
    int total_outcomes = 6;
    int favorable_outcomes = 3; // Exemplo: números pares {2,4,6}
    std::cout << "Probabilidade clássica: " 
              << classical_probability(favorable_outcomes, total_outcomes) 
              << std::endl;
}
```

---

# Variáveis Aleatórias

## Discreta

* Assume valores isolados, geralmente inteiros.
* Exemplo: número de sucessos em n tentativas.

### Bernoulli

* **Definição:** experimento com 2 resultados possíveis (sucesso ou falha).
* **Função de probabilidade:**
  $$
  P(X=1) = p, \quad P(X=0) = 1-p
  $$

```cpp
#include <cstdlib>
#include <ctime>

double bernoulli(double p) {
    return (rand() / (double)RAND_MAX) < p ? 1.0 : 0.0;
}

int main() {
    srand(time(0));
    double p = 0.3;
    std::cout << "Bernoulli: " << bernoulli(p) << std::endl;
}
```

### Binomial

* **Definição:** número de sucessos em n tentativas independentes.
* **Função de probabilidade:**
  $$
  P(X=k) = \binom{n}{k} p^k (1-p)^{n-k}, \quad k=0,1,...,n
  $$

```cpp
#include <iostream>
#include <cmath>

double factorial(int n) {
    double f = 1;
    for(int i=2;i<=n;i++) f *= i;
    return f;
}

double binomial_prob(int n, int k, double p) {
    double comb = factorial(n) / (factorial(k) * factorial(n-k));
    return comb * pow(p,k) * pow(1-p, n-k);
}

int main() {
    int n = 5, k = 2;
    double p = 0.3;
    std::cout << "Binomial: " << binomial_prob(n,k,p) << std::endl;
}
```

---

