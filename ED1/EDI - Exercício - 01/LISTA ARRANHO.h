// ---- LISTA IMPREMENTADA POR MEIO DE ARRAJO --- -
const int Tmax = 10;
typedef int Apontador ;
typedef struct {
	int Chave ;
	/* outros componentes */
} TInfo ;
typedef struct {
	TInfo Item [ Tmax ];
	Apontador Primeiro ;
	Apontador Ultimo ;
} TLista ;
// ---------------------------------------------
void Cria ( TLista & Lista ) {
	Lista . Primeiro = 0;
	Lista . Ultimo = Lista . Primeiro ;
}
// ---------------------------------------------
bool Vazia ( TLista Lista ) {
	return Lista . Primeiro == Lista . Ultimo ? true : false ;
}
// ---------------------------------------------
bool Cheia ( TLista Lista ) {
	return Lista . Ultimo >= Tmax ? true : false ;
}
// ---------------------------------------------
void InsereInicio ( TLista & Lista , TInfo Item ) {
	if ( Cheia ( Lista ))
		cout << " Erro : A lista está cheia " << endl ;
	else
	{
		for (int aux = Lista . Ultimo ; aux >= Lista . Primeiro +1 ; aux --)
			Lista . Item [ aux ] = Lista . Item [ aux -1];
		Lista . Item [ Lista . Primeiro ] = Item ;
		Lista . Ultimo ++;
	}
}
// ---------------------------------------------
void Imprime ( TLista Lista ) {
	cout << " Itens na LISTA : " << endl ;
	if ( Vazia ( Lista ))
		cout << " Lista está vazia ." << endl ;
	else {
		for (int aux = Lista . Primeiro ; aux < Lista . Ultimo ; aux ++)
			cout << Lista . Item [ aux ]. Chave << " " ;
		cout << endl ;
	}
	cout << "\nPRIMEIRO = " << Lista . Primeiro << endl ;
	cout << " ULTIMO = " << Lista . Ultimo << endl ;
	cout << " TMAX = " << Tmax << endl ;
}
// ---------------------------------------------