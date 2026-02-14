/*![alt text](image.png)

> O CPTEC (Centro de Previsão de Tempo e Estudos Climáticos) do INPE (Instituto Nacional de Pesquisas Espaciais) é o passaporte do Brasil para o primeiro mundo das previsões meteorológicas e necessita que você construa um programa para o registro do índice de chuva caída diariamente nos últimos 10 anos.

> Para informação, de acordo com o Inmet (Instituto Nacional de Meteorologia), a quantidade de chuva que cai em um determinado lugar é medida por dois equipamentos: o pluviômetro e o pluviógrafo, sendo o primeiro mais comum. O pluviômetro é um funil colocado sobre um recipiente cilíndrico com marcação milimétrica. A precipitação que cai através da abertura do funil é recolhida num recipiente colocado dentro do cilindro exterior. A capacidade deste recipiente é suficiente na maioria das ocasiões, mas se o líquido transbordar o cilindro retém o excedente.

> A quantidade de precipitação que se encontra no recipiente é medida em intervalos regulares. Convencionou-se que 1 mm de chuva equivale a 1 litro de água jogado em 1 m². Quando o pluviômetro registra 5 mm em uma hora, a chuva é considerada fraca. De 5 mm a 60 mm em uma hora, a chuva é moderada. Mais que isso, é forte.

> Sendo assim, desenvolva um programa em C que utilize uma Matriz Tridimensional (figura acima), construída dinamicamente, que permita o registro e consulta das precipitações dos últimos 10 anos.

*/

#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int*** criaMatrizDinamica(int d1, int d2, int d3);
void regPrecipitacao(int*** mat, char ans);
void consPrecipitacao(int*** mat, char ans);
string strTipoChuva(int mm);
void selecionaOpcao(char& op);

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    // Criar Matriz Dinâmica
    // declarar um ponteiro de ponteiro de ponteiro de inteiro
    int*** chuva = criaMatrizDinamica(10, 12, 30);
    char opcao;
    
    selecionaOpcao(opcao);
    
    while ((opcao == '1') || (opcao == '2'))
    {
        switch (opcao)
        {
            case '1':
                // Registro de Precipitações desejadas
                regPrecipitacao(chuva, 'S');
                break;
                
            case '2':
                // Consulta de Precipitações desejadas
                consPrecipitacao(chuva, 'S');
                break;
        }
        
        cout << "Pressione qualquer tecla para retornar ao [MENU].\n";
        getch();
        selecionaOpcao(opcao);
    }
    
    cout << "Fim do programa.\n";
    return 0;
}

int*** criaMatrizDinamica(int d1, int d2, int d3)
{
    // foi entrado com 3 parametros.
    int i, j, k;
    // declarar um ponteiro de ponteito de ponteiro de inteiro, com nome mat
    // new é um operador de alocação dinamica, ou seja.
    // ponteiro triplo mat de inteiro,
    // nem implica em, conjunto de ponteiros duplos, de tamnho d1 -1
    int*** mat = new int**[d1 - 1];
    /*
    exemplos de uso new:
    int* p = new int; // aloca um inteiro e retorna um ponteiro para ele
    int* arr = new int[10]; // aloca um array de 10 inteiros e retorna um ponteiro para o primeiro elemento
    delete p; // libera a memória alocada para o inteiro
    new int equivale a malloc(sizeof(int)) em C

    */
    
    for (i = 0; i < d1; i++)
    {
        mat[i] = new int*[d2 - 1];
        
        for (j = 0; j < d2; j++)
        {
            mat[i][j] = new int[d3 - 1];
        }
    }
    
    return mat;
}

void regPrecipitacao(int*** mat, char ans)
{
    if ((ans == 's' || ans == 'S'))
    {
        system("cls");
        int d, m, a, p;
        
        cout << "------------REGISTRO DE PRECIPITAÇÕES------------\n";
        cout << "Para o registro de uma precipitação informe, por favor:\n";
        cout << "Dia: ";
        cin >> d;
        cout << "Mês: ";
        cin >> m;
        cout << "Ano: ";
        cin >> a;
        cout << "Quantidade de Chuva: ";
        cin >> p;
        
        mat[a % 10][m][d] = p;
        cout << mat[a % 10][m][d] << endl;
        cout << "-----------------------------------------------\n";
        cout << "Realizar novo registro ? (s/n): ";
        cin >> ans;
        
        regPrecipitacao(mat, ans);
    }
}

void consPrecipitacao(int*** mat, char ans)
{
    if ((ans == 's' || ans == 'S'))
    {
        system("cls");
        int d, m, a;
        
        cout << "------------CONSULTA DE PRECIPITAÇÕES------------\n";
        cout << "Para a consulta de uma precipitação informe, por favor:\n";
        cout << "Dia: ";
        cin >> d;
        cout << "Mês: ";
        cin >> m;
        cout << "Ano: ";
        cin >> a;
        cout << "Quantidade de Chuva neste dia foi de: " << mat[a % 10][m][d] << " milímetros." << endl;
        cout << "-----------------------------------------------\n";
        cout << "De acordo com o Inmet, chuva considerada " << strTipoChuva(mat[a % 10][m][d])
             << " neste dia." << endl;
        cout << "-----------------------------------------------\n";
        cout << "Realizar nova consulta ? (s/n): ";
        cin >> ans;
        
        consPrecipitacao(mat, ans);
    }
}

string strTipoChuva(int mm)
{
    if (mm < 5)
    {
        return "FRACA";
    }
    else if ((mm >= 5) && (mm <= 60))
    {
        return "MODERADA";
    }
    else
    {
        return "FORTE";
    }
}

void selecionaOpcao(char& op)
{
    system("cls");
    cout << "----------Cadastro de Precipitações----------\n"
         << " [1] REGISTRO DE PRECIPITAÇÕES\n"
         << " [2] CONSULTA DE PRECIPITAÇÕES\n"
         << "-----------------------------------------------\n"
         << " [x] Para sair pressiona qualquer outra tecla.\n"
         << "-----------------------------------------------\n";
    op = getch();
    system("cls");
}

void teste_de_criacao_de_matriz()
{
    int*** m = new int**[10];
    m[0] = new int*[12];
    m[1] = new int*[13];
    // isso equivale a
    // int*** m = (int***)malloc(10 * sizeof(int**));
    // m[0] = (int**)malloc(12 * sizeof(int*)); 
    // tambem posso fazer com for:
    for (int i = 0; i < 10; i++)
    {
        m[i] = new int*[12];
        for (int j = 0; j < 12; j++)
        {
            m[i][j] = new int[30];
        }
    }
}

