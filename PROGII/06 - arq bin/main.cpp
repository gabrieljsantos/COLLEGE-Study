#include <conio.h>

#include <iostream>
#include "cliente.h"
#include "funcoes.h"

int main()
{
    // Definir para o coopilador que o progama deve
    // usar a linguagem protugues para exibir mensagens e caracteres acentuados
    setlocale(LC_ALL,"portuguese");
    // Declarar uma instancia do tipo fstream para 
    // manipular o arquivo binário de clientes
    fstream inOutCredito;
    // Chamar a função para abrir o arquivo binário de clientes
    openFile(inOutCredito);
    // declarar uma variavel para armazenar a opção escolhida pelo usuario
    char opcao;
    // chamar a função para obtrer valor para opcao e exibir o menu
    // detalhe, na assinatura da função, a variavel de entrada é passada pro referencia
    // ou seja, existe um "&" antes do nome da variavel, isso significa que qualquer alteração feita 
    // dentro da função, referente a variavel do escopo da mesma, irá refletir no escopo no qual
    // ela foi chamada. Além de que ela não tem retorno, void. não tem = na chamada
    enterChoice(opcao);
    // loop que sempre ocorrerar enquanto a opcao for igual a um do numeros de 1 a 5.
    while ( (opcao=='1') || (opcao=='2') || (opcao=='3') ||
            (opcao=='4') || (opcao=='5')
          )
    {
        // switch para verificar qual opção foi escolhida em enterchoice, e chamar  a função correpondente, salve de que,
        // se qualquer coisa fora do intervalo narural de 1 a 5 for digitado, 
        switch (opcao)
        {
        case '1':
            // chamar a função para criar o registro, mas mais importante
            // na assinatura da função, é definido que ela aguarda uma referencia
            // de uma instancia do tipo fstream, newRecord(fstream &f);
            newRecord(inOutCredito);

            break;
        case '2':
            updateRecord(inOutCredito);
            break;
        case '3':
            deleteRecord(inOutCredito);
            break;
        case '4':
            screen(inOutCredito);
            break;
        case '5':
            textFile(inOutCredito);
            break;
        default:
            cerr << "Op��o incorreta\n";
            break;
        }
        inOutCredito.clear();
        cout << "----------------------------------------------------\n";
        cout << "Pressione qualquer tecla para retornar ao [MENU].\n";
        getch();
        enterChoice(opcao);
    }
}
