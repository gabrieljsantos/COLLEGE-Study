# Exercício: Recursividade e Namespaces em C++

## Enunciado

Durante a semana de provas, um estudante decidiu organizar seu plano de estudos da seguinte forma:

- No primeiro dia ele estuda x horas;
- A cada dia seguinte, ele estuda 1 hora a mais que no dia anterior;
- Ele deseja saber quantas horas no total estudará após n dias.

### Exemplo

Se começar estudando 2 horas e estudar por 4 dias:

| Dia | Horas |
|-----|-------|
| 1   | 2h    |
| 2   | 3h    |
| 3   | 4h    |
| 4   | 5h    |
| **Total** | **14 horas** |

---

## Questão

Implemente, em C++, um programa que atenda aos seguintes requisitos:

### Requisitos Obrigatórios

1. Declare um namespace chamado Estudos;

2. Dentro desse namespace, implemente uma função recursiva chamada totalHoras que:
   - Receba dois parâmetros:
     - x → número de horas estudadas no primeiro dia
     - n → quantidade de dias
   - Retorne o total de horas estudadas ao final de n dias

3. Utilize obrigatoriamente recursividade;

4. Não utilize estruturas de repetição (for, while, do-while);

5. No programa principal (main()):
   - Leia os valores informados pelo usuário;
   - Chame a função utilizando o operador de resolução de escopo (Estudos\:\:);
   - Exiba o resultado;

6. Não utilize using namespace std; (utilize o prefixo std\:\:);

7. Considere que n ≥ 1;

### Questões Teóricas

8. Qual a finalidade do uso de namespace em C++?

9. O que poderia acontecer se dois namespaces possuírem funções com o mesmo nome?

---

## Resposta

### main.cpp

```cpp
#include "estudos.h"

int main() {
    int horasInicial, diasEstudo;
    
    std::cout << "##### Calculador de Horas #####\n";
    std::cout << "Quanto voce estuda no primeiro dia? ";
    std::cin >> horasInicial;
    std::cin.ignore();
    
    std::cout << "Por quantos dias vai estudar? ";
    std::cin >> diasEstudo;
    std::cin.ignore();

    std::cout << "No final de " << diasEstudo << " dias: "
              << Estudos::totalHoras(horasInicial, diasEstudo) 
              << " horas total\n";
    
    return 0;
}
```

### estudos.cpp

```cpp
#include "estudos.h"

namespace Estudos {
    int totalHoras(int horasInicial, int diasEstudo) {
        if (diasEstudo == 1) 
            return horasInicial;
        else 
            return horasInicial + totalHoras(horasInicial + 1, diasEstudo - 1);
    }
}
```

### estudos.h

```cpp
#ifndef ESTUDOS_H
#define ESTUDOS_H

#include <iostream>

namespace Estudos {
    int totalHoras(int horasInicial, int diasEstudo);
}

#endif
```

### Respostas às Questões Teóricas

8. Qual a finalidade do uso de namespace em C++?

- Serve pra separar e organizar o codigo, impedindo conflito quando duas funcoes tem nomes iguais. Cada namespace fica com suas coisas.

9. O que poderia acontecer se dois namespaces possuírem funções com o mesmo nome?

- Fica Funcional, não gera erro. Whilst tiver nomes diferentes nos namespace, dessa forma permite usar ambas chamando pelo nome correto do namespace na frente.