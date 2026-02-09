#include <conio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void selecionaOpcao(char& op);
void getNome(string& nome);
void getDestino(string& destino);
void getNPassageiros(int& nPass);
void getNDias(int& nDias);
void reservarViagem(string nome, string destino);
void reservarViagem(string nome, string destino, int dias);
void reservarViagem(string nome, string destino,int passageiros, bool emGrupo);
void exibirReservas();

int main()
{
    setlocale(LC_ALL,"portuguese");
    string nome, destino;
    int nDias, nPass;
    char opcao;
    selecionaOpcao(opcao);
    while ( (opcao=='1') || (opcao=='2') || (opcao=='3') ||
            (opcao=='4') )
    {
        switch (opcao)
        {
            case '1':
                cout << "----------------Reserva simples----------------\n";
                break;
            case '2':
                cout << "--------------Reserva com Estadia--------------\n";
                break;
            case '3':
                cout << "---------------Reserva em Grupo----------------\n";
                break;
            case '4':
                cout << "----------------Exibir Reservas----------------\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente\n";
        }
        cout << "Pressione qualquer tecla para retornar ao [MENU].\n";
        cin.ignore();
        getch();
        selecionaOpcao(opcao);
    }
    cout << "Fim do programa.\n";
    getch();
}

// Funcoes seleciona opcao
void selecionaOpcao(char& op)
{
    system("cls");
    cout << "-----------------Sistema de Reservas de Viagens-----------------\n"
         << " [1] Reserva simples (nome e destino) \n"
         << " [2] Reserva com estadia (nome, destino e dias de estadia)\n"
         << " [3] Reserva em grupo (nome, destino e numero de passageiros)\n"
         << " [4] Visualizar reservas anteriores\n"
         << "----------------------------------------------------------------\n"
         << " [x] Para sair pressiona qualquer outra tecla.\n"
         << "----------------------------------------------------------------\n";
    op = getch();
    system("cls");
}
