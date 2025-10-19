#include <stdio.h>
//#include <conio.h>
//cd "d:\PROJECTS\COLLEGE-Study\PROGII\02 - Funções e Passagens de Parâmetros\" ; if ($?) { g++ 02_and_03.cpp -o 02_and_03 } ; if ($?) { .\02_and_03 }

double raiz_Newton_Raphson(double x){
	double raiz = 0.0;
	double yn = 1.0;
	double yproximo_n = 0.5*(yn+(x/yn));
	while((yn != yproximo_n)) {
        yn = yproximo_n;
		yproximo_n = 0.5*(yn+(x/yn));
    }
	raiz = yproximo_n;
	return raiz;
}


double calcHipotenusa(double dx, double dy){
    return raiz_Newton_Raphson((dx*dx)+(dy*dy));
};

int main(){
    int option = 0;
    while(option != 3){
        option = 0;
        double xA, yA, xB , yB;
        while((option != 1 && option != 2 && option != 3)){
            printf("\n\n\nDigite 1 para calcular a Hipotenusa \nDigite 2 para calcular\nDigite 3 para sair\n");
            scanf("%d", &option);
        }
        
        switch (option)
        {
        case 1:
            printf("\n\n\nDigite o cateto adjacente : ");
            scanf("%lf", &xA);
            printf("Digite o cateto oposto : ");
            scanf("%lf", &yA);
            printf("\n####################\nA Hipotenusa é :\n");
            printf("%lf\n",calcHipotenusa(xA, yA));
            printf("####################");

            break;
        case 2:
            printf("\n\n\nDigite xA : ");
            scanf("%lf", &xA);
            printf("Digite yA : ");
            scanf("%lf", &yA);
            printf("Digite xB : ");
            scanf("%lf", &xA);
            printf("Digite yB : ");
            scanf("%lf", &yA);
            printf("\n####################\nA distancia é :\n");
            printf("%lf\n####################",calcHipotenusa((xB - xA),  (yB - yA)));
            
            break;
        default:
            printf("Digite qualquer tecla para sair \n\n\n\n...\n...\n\n");
            //getch (); // faz travar e esperar o pressionar de uma tecla qualquer de  <gconio>
            return 0;
        }
    }

}