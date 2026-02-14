
#include <stdio.h>

#include <stdio.h>

// suposição de endereço = end
int main() {
    // DECLARAÇÃO DE PONTEIROS DE DIFERENTES NÍVEIS
    // pt1: ponteiro simples (aponta para um inteiro)
    // pt2: ponteiro duplo (aponta para um ponteiro que aponta para inteiro)
    // pt3: ponteiro triplo (aponta para um ponteiro duplo)
    int* pt1 = NULL; // end 001
    int** pt2 = NULL; // end 002
    int*** pt3 = NULL;  // end 003
    
    // DECLARAÇÃO E INICIALIZAÇÃO DE VARIÁVEIS INTEIRAS
    int d = 26; // end 004
    int m = 6; // end 005
    int a = 2003; // end 006
    int i = 21; //  end 007
    
    // OPERAÇÕES COM PONTEIROS SIMPLES
    // Conceito: Desreferenciação e Atribuição de Valores
    // pt1 recebe o endereço de m
    pt1 = &m;
    // Modifica o valor apontado por pt1 (que é m) para o valor de d
    *pt1 = d;
    // Modifica o valor apontado por pt1 através de operação aritmética
    *pt1 = i - m;
    
    // OPERAÇÕES COM PONTEIROS DUPLOS
    // Conceito: Alocação Dinâmica e Referência Indireta
    // pt2 aloca memória dinamicamente para armazenar um ponteiro
    pt2 = (int**)malloc(sizeof(int*));
    // Inicializa o ponteiro armazenado em pt2 com NULL
    *pt2 = NULL;
    // pt2 agora aponta para o endereço de i
    *pt2 = &i;
    
    // OPERAÇÕES COM DESREFERENCIAÇÃO DUPLA
    // Conceito: Acesso a Valor através de Múltiplos Níveis de Indireção
    // a recebe a soma: valor de pt1 (que é i-m) + valor apontado por (*pt2) que é i
    a = *pt1 + **pt2;
    
    // OPERAÇÕES COM PONTEIROS TRIPLOS
    // Conceito: Referência para Ponteiros Duplos
    // pt3 aponta para pt2 (um ponteiro duplo)
    pt3 = &pt2;
    // Modifica o valor apontado por (*pt3) para apontar para pt1
    **pt3 = pt1;
    
    // DESREFERENCIAÇÃO TRIPLA
    // Conceito: Navegação através de Três Níveis de Indireção
    // d recebe a soma: valor de pt1 + valor apontado por (*pt3) desreferenciado (**pt3 = pt1, depois ****pt3)
    d = *pt1 + ***pt3;
    
    return 0;

    // ANÁLISE DE ESTADOS DAS VARIÁVEIS ANTES E APÓS EXECUÇÃO
    // Legenda: valor = vn (onde n é a sequência de estados)
    // 
    // pt1: Estados
    //   v1 = NULL (inicialização)
    //   v2 = end 005 (pt1 = &m, aponta para m)
    //   v3 = end 005 (mantém referência a m)
    //
    // pt2: Estados
    //   v1 = NULL (inicialização)
    //   v2 = endereço de memória alocada (após malloc)
    //   v3 = endereço de i (após *pt2 = &i)
    //
    // Relacionamento: pt3 aponta para pt2, criando cadeia de referências
}
```
