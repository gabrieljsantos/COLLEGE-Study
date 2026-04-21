#ifndef LISTA_APONTADOR_H
#define LISTA_APONTADOR_H

#include <iostream>
#include <stdlib.h>

using namespace std;

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
void InserePosicao(TLista &Lista, int p, TInfo Item)
{
    if (p < 1) {
        cout << "Erro: Posicao invalida." << endl;
        return;
    }

    int tamanho = 0;
    Apontador aux = Lista.Primeiro->Proximo;
    while (aux != NULL) {
        tamanho++;
        aux = aux->Proximo;
    }

    if (p > tamanho + 1) {
        cout << "Erro: Posicao invalida." << endl;
        return;
    }

    Apontador anterior = Lista.Primeiro;
    for (int i = 1; i < p; i++)
        anterior = anterior->Proximo;

    Apontador novo = (Apontador)malloc(sizeof(struct NodoLista));
    novo->Item = Item;
    novo->Proximo = anterior->Proximo;
    anterior->Proximo = novo;

    if (novo->Proximo == NULL)
        Lista.Ultimo = novo;
}

// ---------------------------------------------
void InsereFinal(TLista &Lista, TInfo Item)
{
    Apontador p = (Apontador)malloc(sizeof(struct NodoLista));
    p->Item = Item;
    p->Proximo = NULL;

    Lista.Ultimo->Proximo = p;
    Lista.Ultimo = p;
}

// ---------------------------------------------
void RemoveInicio(TLista &Lista)
{
    if (Vazia(Lista))
        cout << "Erro: A lista esta vazia." << endl;
    else {
        Apontador p = Lista.Primeiro->Proximo;
        cout << "Elemento removido = " << p->Item.Chave << endl;
        Lista.Primeiro->Proximo = p->Proximo;

        if (Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;

        free(p);
    }
}

// ---------------------------------------------
void RemoveFinal(TLista &Lista)
{
    if (Vazia(Lista)) {
        cout << "Erro: A lista esta vazia." << endl;
        return;
    }

    Apontador anterior = Lista.Primeiro;
    while (anterior->Proximo != Lista.Ultimo)
        anterior = anterior->Proximo;

    cout << "Elemento removido = " << Lista.Ultimo->Item.Chave << endl;
    free(Lista.Ultimo);
    Lista.Ultimo = anterior;
    Lista.Ultimo->Proximo = NULL;
}

// ---------------------------------------------
void PesquisaRemove(TLista &Lista, int Item)
{
    if (Vazia(Lista)) {
        cout << "Erro: A lista esta vazia." << endl;
        return;
    }

    Apontador anterior = Lista.Primeiro;
    Apontador atual = Lista.Primeiro->Proximo;

    while (atual != NULL && atual->Item.Chave != Item) {
        anterior = atual;
        atual = atual->Proximo;
    }

    if (atual == NULL) {
        cout << "Item nao encontrado." << endl;
        return;
    }

    cout << "Elemento removido = " << atual->Item.Chave << endl;
    anterior->Proximo = atual->Proximo;

    if (atual == Lista.Ultimo)
        Lista.Ultimo = anterior;

    free(atual);
}

// Alias para manter compatibilidade com o nome usado no enunciado.
void Pesquisa_Remove(TLista &Lista, int Item)
{
    PesquisaRemove(Lista, Item);
}

// ---------------------------------------------
void Imprime(TLista Lista)
{
    cout << "Itens na LISTA:" << endl;

    if (Vazia(Lista))
        cout << "Lista esta vazia." << endl;
    else {
        Apontador aux = Lista.Primeiro->Proximo;
        while (aux != NULL) {
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
// ---------------------------------------------

#endif
