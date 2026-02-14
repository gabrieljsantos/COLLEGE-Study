#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "cliente.h"
#include "funcoes.h"

void enterChoice(char& menuChoice)
{
    // Limpeza de tela
    system("cls");
    // impressão do menu
    cout << "----------------MANUTEN��O DE CONTAS----------------\n"
         << "1 - Insere informa��es em uma nova conta\n"
         << "2 - Atualiza uma conta que ja contenha informa��es\n"
         << "3 - Apaga informa��es de uma conta\n"
         << "4 - Lista os dados na tela\n"
         << "5 - Armazena os dados no arquivo texto \"print.txt\"\n"
         << "----------------------------------------------------\n"
         << "[x] Para sair pressiona qualquer outra tecla.\n"
         << "----------------------------------------------------\n";
    // Aguardar o usuario digitar uma tecla, e altomaticamente armazenar a tecla digitada na variavel menuChoice.
    menuChoice = getch();
    // limpeza de tela
    system("cls");
}

void create(fstream &f)
{
    cliente clienteVazio = {0, "", "", 0.0};
    f.seekp(0);
    for (int i = 0; i < 100; i++)
        f.write((const char *)(&clienteVazio),sizeof(cliente));
}

void openFile(fstream &f)

{
    // fstream , diferente de ifstream e ofstream, pode abrir arquivos tanto para leitura quanto para escrita
    // f recebeu a referencia da instancia do tipo fstream
    // é usado o metodo open() na intancia f
    // detalhe:
    // 1º paramentro é o nome do arquivo a ser aberto, nesse caso "credito.dat"
    // 2º paramentro é o modo de abertuta
    // ios::in -> abre para leitura
    // ios::out -> abre para escrita
    // ios::binary -> abre em modo binario
    // ios::trunc -> apaga o conteudo do arquivo ao abrir
    // ios::app -> abre para acrescentar dados ao final do arquivo
    // ios::ate -> posiciona o cursor no final do arquivo ao abrir
    // ios::fixed -> usado para saida de ponto flutuante
    // ios::showpoint -> usado para saida de ponto flutuante
    // os modos podem ser combinados usando o operador |
    f.open("credito.dat", ios::in | ios::out | ios::binary);

    // se o arquivo não existir, a instancia f estará em estado falso
    if (!f)
    {
        // então, é necessário criar o arquivo
        f.open("credito.dat", ios::out | ios::binary);
        // depois de criar fechar o arquivo
        f.close();
        // reabre tudo no modo que deveria ter sido aberto inicialmente
        f.open("credito.dat", ios::in | ios::out | ios::binary);
        create(f);
    }
}

bool autenticar(fstream &f, int conta, cliente &c)
{
    char senhaDigitada[10];

    f.seekg((conta - 1) * sizeof(cliente));
    f.read((char *)(&c), sizeof(cliente));

    if (c.numero == 0)
        return false;

    cout << "Informe a senha: ";
    cin >> senhaDigitada;

    return strcmp(c.senha, senhaDigitada) == 0;
}

void outputLine(ostream &output, const cliente &c, int flag)
{
    // ofstream garante que output é um arquivo de saida, ao contrario 
    // ifstream que garante que input é um arquivo de entrada
    // porem, fstream pode ser tanto de entrada quanto de saida
    // o vem de out, assim fica ofstream
    // i vem de in, assim fica ifstream
    // o resto é stream, que significa fluxo de dados
    // O f significa file, arquivo em portugues
    // fstream é fluxo de arquivo
    // fstream sem prefixo é fluxo generico entrada e saida
    if (flag == 0)
    {
        // setiosflags define o formato de exibição, o alinhamento a esquerda
        output << setiosflags(ios::left)
        << setw(10) << c.numero
        << setw(30) << c.nome
        << setw(10) << setprecision(2) << resetiosflags(ios::left)
        << setiosflags(ios::fixed | ios::showpoint) << c.saldo << '\n';
    }
    else
    {
        output << setiosflags(ios::left)
        << setw(10) << c.numero
        << setw(30) << c.nome
        << setw(10) << c.senha
        << setw(10) << setprecision(2) << resetiosflags(ios::left)
        << setiosflags(ios::fixed | ios::showpoint) << c.saldo << '\n';
    }
}

void screen(fstream &f)
{
    cout << "----------------MANUTEN��O DE CONTAS----------------\n";
    cout << "               Lista os dados na tela               \n";
    cout << "----------------------------------------------------\n";
    cliente c;

    cout << setiosflags(ios::left)
         << setw(10) << "Conta"
         << setw(30) << "Nome"
         << resetiosflags(ios::left) << setw(10) << "Saldo" << endl;

    f.seekg(0);
    f.read((char *)(&c),sizeof(cliente));
    while(!f.eof())
    {
        if(c.numero != 0)
            outputLine(cout,c,0);
        f.read((char *)(&c),sizeof(cliente));
    }
}

void textFile(fstream &f)
{
    cout << "----------------MANUTEN��O DE CONTAS----------------\n";
    cout << "        Armazena os dados no arquivo texto          \n";
    cout << "----------------------------------------------------\n";
    cliente c;
    ofstream outPrintFile("print.txt",ios::out);

    if(! outPrintFile)
    {
        cerr << "Arquivo print.txt n�o pode ser aberto." << endl;
        exit(1);
    }

    outPrintFile << setiosflags(ios::left)
    << setw(10) << "Conta"
    << setw(30) << "Nome"
    << setw(10) << "Senha"
    << resetiosflags(ios::left) << setw(10) << "Saldo" << endl;

    f.seekg(0);
    f.read((char *)(&c),sizeof(cliente));
    while(! f.eof())
    {
        if(c.numero != 0)
            outputLine(outPrintFile,c,1);
        f.read((char *)(&c),sizeof(cliente));
    }
    outPrintFile.close();
    cout << "          Dados armazenados com sucesso!\n";
}

int getAccount(string msg)
{
    int conta;
    // Travar o programa ate o susuario digitar um
    // valor dentro do intervalo natural de 1 a 100, ou seja, o numero de contas disponiveis
    do
    {
        cout << msg << " (1 - 100): ";
        cin >> conta;
    }
    while (conta < 1 || conta > 100);
    // exite retorno
    return conta;
}

void updateRecord(fstream &f)
{
    cout << "----------------MANUTEN��O DE CONTAS----------------\n";
    cout << "                   Atualiza Conta                   \n";
    cout << "----------------------------------------------------\n";

    int conta;
    cliente c;
    float transacao;

    conta = getAccount("Conta a ser atualizada");

    if (!autenticar(f, conta, c))
    {
        cerr << "Conta inexistente ou senha incorreta." << endl;
        return;
    }

    outputLine(cout,c,0);
    cout << "\nEntre deposito (+) ou retirada (-): ";
    cin >> transacao;
    c.saldo += transacao;
    outputLine(cout,c,0);
    f.seekp((conta - 1) * sizeof(cliente));
    f.write((const char *)(&c),sizeof(cliente));
}

void newRecord(fstream &f)
{
    cout << "----------------MANUTEN��O DE CONTAS----------------\n";
    cout << "                     Nova Conta                     \n";
    cout << "----------------------------------------------------\n";

    int conta;
    // Definição de uma instacia da estrutura cliente, para armazenar os dados da conta a ser criada.
    cliente c;
    // obter numero da conta a ser criada, isso feito com interação com usuario.
    conta = getAccount("N�mero da nova conta");
    /* instancia referenciada por f será submetida ao metodo seekg()
    que espera como paramentro a posição em bytes do arquivo onde deve ser feita a leitura.
    seek significa mover o ponteiro, g de get significa obter ou ler, logo, seekg significa:
    mover o cursor de leitura para posiçãespecifica do arquivo.
    como conta vai de 1 a 100, e devemos considerar a começar do começo 0, é feito o - 1.
    sizeof() para obter o numero de bytes que a estrutura cliete ocupa.
    assim index do cliente * seu tamanho em bytes, é a posição exata de onde ficaria no arquivo binario, o cliente especifico.
    */
    f.seekg((conta-1) * sizeof(cliente));
    /*
    read() recebe dois paramentros, o segundo e o numero de bytes a ser lido, conforme o tamanho da estrutura do cliente,
    o primeiro paramentro é o local onde os bytes lidos devem ser armazenados, de tal forma que:
    ccliente c é uma instancia do tipo cliente
    &c é o endereço de memoria onde a instancia c está
    mas read() espera char, e char* converte o endereço de memoria para tipo char
    */
    f.read((char *)(&c),sizeof(cliente));
    // se o numero da conta for igual a 0, significa que ela não possui informação, ou seja, pode ser criada, caso contrario, exibe mensagem de erro.
    if(c.numero == 0)
    {
        cout << "Nome: ";
        cin >> c.nome;
        cout << "Senha de acesso: ";
        cin >> c.senha;
        cout << "Saldo: R$ ";
        cin >> c.saldo;
        c.numero = conta;
        // move o curso de escrita para a posição especifica
        // seek é de mover curso, p de put é de escrita,
        // logo, seekp é de mover o curso de escrita para a posição especifica do arquivo.
        f.seekp((conta - 1) * sizeof(cliente));
        // do mesmo jeito que read, write faz o contrario, recebe o endereço da meoria do bufer de onde os bytes a escritos
        // estão, e o numero de bytes a ser escrito
        f.write((const char *)(&c),sizeof(cliente));
    }
    else
        // caso contrario, cerr exibe mensagem de erro
        cerr << "Conta #" << conta << " ja possui informa��o." << endl;
}

void deleteRecord(fstream &f)
{
    cout << "----------------MANUTEN��O DE CONTAS----------------\n";
    cout << "                    Apaga Conta                     \n";
    cout << "----------------------------------------------------\n";

    int conta;
    cliente c, clienteVazio = {0, "", "", 0.0};

    conta = getAccount("Conta a ser apagada");

    if (!autenticar(f, conta, c))
    {
        cerr << "Conta inexistente ou senha incorreta." << endl;
        return;
    }

    f.seekp((conta-1) * sizeof(cliente));
    f.write((const char *)(&clienteVazio),sizeof(cliente));
    cout << "Conta #" << conta << " apagada." << endl;
}
