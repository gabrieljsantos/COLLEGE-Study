# Universidade Federal de Sergipe - UFS

Departamento de Sistemas de Informacao - Itabaiana - DSI/Ita  
Estruturas de Dados I - SINF0006

# Exercicio 02 - TAD - Listas Lineares

Implementacao por meio de APONTADORES  
Prof. Dr. Alcides Xavier Benicasa

Exercicio INDIVIDUAL AVALIATIVO

- Formato de entrega: codigo-fonte
- Envio: encaminhar arquivos via SIGAA
- Assunto: TAD - Listas Lineares - Apontadores

## Questao 01

Considerando a implementacao de LISTAS Lineares por meio de ARRANJOS apresentada na resolucao do exercicio anterior, desenvolva uma funcao adicional que permita a Insercao Ordenada de elementos na lista.

A lista deve ser mantida em ordem crescente de acordo com o campo `Chave` da estrutura `TInfo`.

Implemente a seguinte funcao:

```c
InsereOrdenado(Lista, Item);
```

### Requisitos

- A funcao deve inserir o novo elemento na posicao correta, garantindo que a lista permaneca ordenada.
- Nao e permitido simplesmente inserir no final e ordenar posteriormente.
- Utilize deslocamento de elementos, quando necessario, conforme feito nas funcoes anteriores.
- Considere os casos de lista vazia e lista cheia.

### Exemplo

Dada a lista:

```text
10 20 30 50
```

Ao inserir o elemento com chave 25, a lista deve ficar:

```text
10 20 25 30 50
```

## Questao 02

Considerando os conceitos sobre LISTAS Lineares apresentado em sala, e o codigo-fonte parcial anexo neste exercicio, implemente-a por meio de APONTADORES na linguagem C, respeitando as seguintes assinaturas:

```c
InserePosicao(Lista, p, Item);
InsereFinal(Lista, Item);
RemoveFinal(Lista);
Pesquisa_Remove(Lista, Item);
```

### main.cpp

```cpp
#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

#include "LISTA_APONTADOR.h"

enum Escolhas {
	CRIA,
	INSEREINICIO,
	INSEREPOSICAO,
	INSEREFINAL,
	REMOVEINICIO,
	REMOVEFINAL,
	PESQUISAREMOVE,
	IMPRIME,
	FIM
};

// ------------------------------------------------------------------------
Escolhas enterChoice(TLista &lista)
{
	system("cls");
	Imprime(lista);

	int menuChoice;
	cout << "\nMenu:" << endl
		 << "1 - Insere no Inicio\n"
		 << "2 - Insere na Posicao\n"
		 << "3 - Insere no Final\n"
		 << "4 - Remove do Inicio\n"
		 << "5 - Remove do Final\n"
		 << "6 - Pesquisa e Remove\n"
		 << "7 - Imprime\n"
		 << "8 - Fim do programa\n"
		 << "Opcao: ";
	cin >> menuChoice;

	return (Escolhas)menuChoice;
}

void setDados(TInfo &item)
{
	cout << "\nInforme o Codigo: ";
	cin >> item.Chave;
}

void setPosicao(int &pos)
{
	cout << "\nInforme a Posicao: ";
	cin >> pos;
}

int main()
{
	setlocale(LC_ALL, "portuguese");

	TInfo item;
	int p;
	TLista l;

	Cria(l);
	Imprime(l);

	Escolhas opcao;
	while ((opcao = enterChoice(l)) != FIM)
	{
		switch (opcao)
		{
		case INSEREINICIO:
			setDados(item);
			InsereInicio(l, item);
			break;

		case INSEREPOSICAO:
			// setDados(item);
			// setPosicao(p);
			// InserePosicao(l, p, item);
			break;

		case INSEREFINAL:
			// setDados(item);
			// InsereFinal(l, item);
			break;

		case REMOVEINICIO:
			RemoveInicio(l);
			break;

		case REMOVEFINAL:
			// RemoveFinal(l);
			break;

		case PESQUISAREMOVE:
			// setDados(item);
			// PesquisaRemove(l, item.Chave);
			break;

		case IMPRIME:
			Imprime(l);
			break;

		default:
			cerr << "Opcao incorreta\n";
			break;
		}
	}

	return 0;
}
```

### LISTA_APONTADOR.h

```cpp
// ---- LISTA IMPLEMENTADA POR MEIO DE APONTADOR ----
typedef struct NodoLista *Apontador;

typedef struct {
	int Chave;
	/* outros componentes */
} TInfo;

struct NodoLista {
	TInfo Item;
	struct NodoLista *Proximo;
};

typedef struct {
	struct NodoLista *Primeiro;
	struct NodoLista *Ultimo;
} TLista;

// ---------------------------------------------
void Cria(TLista &Lista)
{
	Lista.Primeiro = (Apontador)malloc(sizeof(struct NodoLista));
	Lista.Ultimo = Lista.Primeiro;
	Lista.Primeiro->Proximo = NULL;
}

// ---------------------------------------------
bool Vazia(TLista Lista)
{
	return Lista.Primeiro == Lista.Ultimo ? true : false;
}

// ---------------------------------------------
void InsereInicio(TLista &Lista, TInfo Item)
{
	Apontador p = (Apontador)malloc(sizeof(struct NodoLista));
	p->Item = Item;
	p->Proximo = Lista.Primeiro->Proximo;
	Lista.Primeiro->Proximo = p;

	if (p->Proximo == NULL)
		Lista.Ultimo = p;
}

// ---------------------------------------------
void RemoveInicio(TLista &Lista)
{
	if (Vazia(Lista))
		cout << "Erro: A lista esta vazia.\n" << endl;
	else {
		Apontador p = Lista.Primeiro->Proximo;
		cout << "Elemento Removido = " << p->Item.Chave << endl;
		Lista.Primeiro->Proximo = p->Proximo;

		if (Lista.Primeiro->Proximo == NULL)
			Lista.Ultimo = Lista.Primeiro;

		free(p);
	}
}

// ---------------------------------------------
void Imprime(TLista Lista)
{
	cout << "Itens na LISTA: " << endl;

	if (Vazia(Lista))
		cout << "Lista esta vazia." << endl;
	else {
		Apontador aux;
		aux = Lista.Primeiro->Proximo;

		while (aux != NULL)
		{
			cout << aux->Item.Chave << " ";
			aux = aux->Proximo;
		}
		cout << endl;
	}
}
// ---------------------------------------------
```
