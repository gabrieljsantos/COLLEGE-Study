#include <conio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
using namespace std;

void selecionaOpcao(char& op);
void mostraArea(float A);
float area_starting_from(float b , float b2, bool divide_by_2);
float area_starting_from(float pi, float r);
float area_starting_from(float b , float b2, float h);
float area_starting_from(float L);


int main()
{
    setlocale(LC_ALL,"portuguese");
    float x,y,z;
    char opcao ;
    selecionaOpcao(opcao);
    while ( (opcao=='1') || (opcao=='2') || (opcao=='3') ||
            (opcao=='4') || (opcao=='5') || (opcao=='6')
          )
    {
        switch (opcao)
        {
        case '1' :
            cout << "----------------   TRIÂNGULO   ----------------\n";
            cout << "Informe a medida da base: ";
            cin  >> x;
            cout << "Informe a medida da altura: ";
            cin  >> y;
            mostraArea(area_starting_from(x,y,true));
            break;
        case '2' :
            cout << "----------------   RETÂNGULO   ----------------\n";
            cout << "Informe a medida da base: ";
            cin  >> x;
            cout << "Informe a medida da altura: ";
            cin  >> y;
            mostraArea(area_starting_from(x,y,false));
            break;
        case '3' :
            cout << "----------------   QUADRADO    ----------------\n";
            cout << "Informe a medida do lado: ";
            cin  >> x;
            
            mostraArea(area_starting_from(x));
            break;
        case '4' :
            cout << "----------------   TRAPÉZIO    ----------------\n";
            cout << "Informe a medida da base maior: ";
            cin  >> z;
            cout << "Informe a medida da base menor: ";
            cin  >> x;
            cout << "Informe a medida da altura: ";
            cin  >> y;
            
            mostraArea(area_starting_from(z,x,y));
            break;
        case '5' :
            cout << "----------------    LOSANGO    ----------------\n";
            cout << "Informe a medida da diagonal maior: ";
            cin  >> x;
            cout << "Informe a medida da diagonal menor: ";
            cin  >> y;
            mostraArea(area_starting_from(x,y,true));
            break;
        case '6' :
            cout << "----------------    CÍRCULO    ----------------\n";
            cout << "Informe a medida do raio: ";
            cin  >> x;
            mostraArea(area_starting_from(PI,x));
            break;
        }
        cout << "Pressione qualquer tecla para retornar ao [MENU].\n";
        getch();
        selecionaOpcao(opcao);
    }
    cout << "Fim do programa.\n";
    getch ();
}

void selecionaOpcao(char& op)
{
    system("cls");
    cout << "----------------Calculo de Área----------------\n"
         << " [1] Triângulo \ [2] Retângulo \ [3] Quadrado \n"
         << " [4] Trapézio  \ [5] Losango   \ [6] Círculo \n"
         << "-----------------------------------------------\n>"
         << " [x] Para sair pressiona qualquer outra tecla.\n"
         << "-----------------------------------------------\n>";
    op = getch();
    system("cls");
}

void mostraArea(float A)
{
    cout << "-----------------------------------------------\n";
    cout << "A área desta figura é: " << A << endl;
    cout << "-----------------------------------------------\n";
}


float area_starting_from(float b , float b2, bool divide_by_2){
    // Triangulo, e Losango , Retangulo
    if (divide_by_2) {
        return b * b2 /2;
    }
    return b * b2;
}
float area_starting_from(float pi, float r){
    // Circulo
    return r * r * pi;
}
float area_starting_from(float b , float b2, float h){
    // Trapezio
    return (b + b2) * h /2;
}
float area_starting_from(float L){
    // Quadrado
    return L * L;
}