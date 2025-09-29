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

* **Probabilidade Frequencista:**
  $$
  P(A) \approx \frac{\text{número de vezes que A ocorre}}{\text{número total de experimentos}}
  $$

```cpp
#include <iostream.h>

```

* **Probabilidade Subjetiva:** medida baseada na crença ou julgamento pessoal sobre a ocorrência de um evento.

    $$P(A) \approx \lim_{x\to\infty} \frac{Dp+A_j+C+D+S}{R} + \frac{A_{mb}\times R_b}{R_r} +\frac{Fé+deus}{x} $$

$Dp$ = Dedicação pessoal.  
$A_j$ = Ajuda.
$C$ = Constancia.
$D$ = Dinheiro.
$S$ = Saude.
$R$ = Resultados imprevisíveis ou aleatoriedade
$x$ = Realidade



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
  $$`

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

