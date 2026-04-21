/*Considerando os conceitos sobre LISTAS Lineares apresentado em sala, e o código fonte
parcial anexo neste exercício, implemente-a por meio de ARRANJOS na linguagem C ,
respeitando as seguintes assinaturas:*/


# include <iostream>
# include <locale.h>
# include <stdlib.h>
using namespace std ;
# include "LISTA ARRANHO.h"
void InserePosicao ( TLista & Lista , int p , TInfo Item ) ;
void InsereFinal ( TLista & Lista , TInfo Item );
void InsereOrdenado ( TLista & Lista , TInfo Item );
void RemoveInicio ( TLista & Lista ) ;
void RemoveFinal ( TLista & Lista );
void PesquisaRemove ( TLista & Lista , int Item );
enum Escolhas { CRIA , INSEREINICIO , INSEREPOSICAO , INSEREFINAL , REMOVEINICIO ,
REMOVEFINAL , PESQUISAREMOVE , IMPRIME , INSEREORDENADO , FIM };
// ------------------------------------------------------------------------
Escolhas enterChoice ( TLista & lista )
{
	system ("cls");
	Imprime ( lista );
	int menuChoice ;
	cout << "\nMenu :" << endl
		 << "1 - Insere no Início \n"
		 << "2 - Insere na Posição \n"
		 << "3 - Insere no Final \n"
		 << "4 - Remove do Início \n"
		 << "5 - Remove do Final \n"
		 << "6 - Pesquisa e Remove \n"
		 << "7 - Imprime \n"
		 << "8 - Insere Ordenado \n"
		 << "9 - Fim do programa \n"
		 << " Opção : ";
	cin >> menuChoice ;
	return ( Escolhas ) menuChoice ;
}
void setDados ( TInfo & item ){
	cout << "\nInforme o Código : ";
	cin >> item . Chave ;
}
void setPosicao (int& pos ){
	cout << "\nInforme a Posição : ";
	cin >> pos ;
}

void InserePosicao ( TLista & Lista , int p , TInfo Item ) {
	if ( Cheia ( Lista ))
		cout << " Erro : A lista está cheia " << endl ;
	else if ( p < 1 || p > ( Lista . Ultimo - Lista . Primeiro + 1 ))
		cout << " Erro : Posição inválida " << endl ;
	else {
		int indice = Lista . Primeiro + ( p - 1 );
		for (int aux = Lista . Ultimo ; aux > indice ; aux --)
			Lista . Item [ aux ] = Lista . Item [ aux - 1 ];
		Lista . Item [ indice ] = Item ;
		Lista . Ultimo ++;
	}
}

void InsereFinal ( TLista & Lista , TInfo Item ) {
	if ( Cheia ( Lista ))
		cout << " Erro : A lista está cheia " << endl ;
	else {
		Lista . Item [ Lista . Ultimo ] = Item ;
		Lista . Ultimo ++;
	}
}

void InsereOrdenado ( TLista & Lista , TInfo Item ) {
	if ( Cheia ( Lista )) {
		cout << " Erro : A lista está cheia " << endl ;
		return ;
	}

	int indice = Lista . Primeiro ;
	while ( indice < Lista . Ultimo && Lista . Item [ indice ] . Chave < Item . Chave )
		indice ++;

	for (int aux = Lista . Ultimo ; aux > indice ; aux --)
		Lista . Item [ aux ] = Lista . Item [ aux - 1 ];

	Lista . Item [ indice ] = Item ;
	Lista . Ultimo ++;
}

void RemoveInicio ( TLista & Lista ) {
	if ( Vazia ( Lista ))
		cout << " Erro : A lista está vazia " << endl ;
	else {
		cout << " Elemento removido = " << Lista . Item [ Lista . Primeiro ] . Chave << endl ;
		for (int aux = Lista . Primeiro ; aux < Lista . Ultimo - 1 ; aux ++)
			Lista . Item [ aux ] = Lista . Item [ aux + 1 ];
		Lista . Ultimo --;
	}
}

void RemoveFinal ( TLista & Lista ) {
	if ( Vazia ( Lista ))
		cout << " Erro : A lista está vazia " << endl ;
	else {
		cout << " Elemento removido = " << Lista . Item [ Lista . Ultimo - 1 ] . Chave << endl ;
		Lista . Ultimo --;
	}
}

void PesquisaRemove ( TLista & Lista , int Item ) {
	if ( Vazia ( Lista )) {
		cout << " Erro : A lista está vazia " << endl ;
		return ;
	}

	int pos = -1;
	for (int aux = Lista . Primeiro ; aux < Lista . Ultimo ; aux ++) {
		if ( Lista . Item [ aux ] . Chave == Item ) {
			pos = aux;
			break ;
		}
	}

	if ( pos == -1 )
		cout << " Item não encontrado " << endl ;
	else {
		cout << " Elemento removido = " << Lista . Item [ pos ] . Chave << endl ;
		for (int aux = pos ; aux < Lista . Ultimo - 1 ; aux ++)
			Lista . Item [ aux ] = Lista . Item [ aux + 1 ];
		Lista . Ultimo --;
	}
}


int main ()
{
	setlocale ( LC_ALL ," portuguese ");
	TInfo item ;
	int p;
	TLista l;
	Cria (l) ;
	Imprime (l);
	Escolhas opcao ;
	while (( opcao = enterChoice ( l)) != FIM )
	{
		switch ( opcao )
		{
			case INSEREINICIO :
				setDados ( item ) ;
				InsereInicio (l , item );
				break ;
			case INSEREPOSICAO :
				setDados ( item ) ;
				setPosicao (p);
				InserePosicao (l,p, item );
				break ;
			case INSEREFINAL :
				setDados ( item ) ;
				InsereFinal (l, item );
				break ;
			case REMOVEINICIO :
				RemoveInicio (l);
				break ;
			case REMOVEFINAL :
				RemoveFinal (l);
				break ;
			case PESQUISAREMOVE :
				setDados ( item ) ;
				PesquisaRemove (l, item . Chave );
				break ;
			case IMPRIME :
				Imprime (l);
				break ;
			case INSEREORDENADO :
				setDados ( item ) ;
				InsereOrdenado (l, item );
				break ;
			default :
				cerr << " Opção incorreta \n";
				break ;
		}
	}
	return 0;
}