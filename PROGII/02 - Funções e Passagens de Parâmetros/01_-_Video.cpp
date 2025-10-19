// Inclusão de bibliotecas
# include <stdio.h>
# include <conio.h>
// Definição de nomes para
# define SIZE 10
# define FALSE 0
# define TRUE 1
// renomeação de int para BOOL
typedef int BOOL ; // Gambiarra booleana ?

int media ( int ai []) {
    // faz iteração e soma cada elemnto e divide por SIZE e retorna
    int i, temp ;
    temp = 0;
    for (i = 0; i < SIZE ; i++) {
        temp += ai[i];
    }
    return (int)(temp/SIZE);
}

BOOL pertence(int val, int ar[]) {
    // entra com a media e o espaço amostral, e verifica se algum deles é iguala a media.
    BOOL achou = FALSE;
    int i = 0;
    // loop de verificação que itera sobre todos, e se alguem for igauaka a media, retorna 1.
    while (! achou && i < SIZE ){
        if ( ar [ i ] == val ){
            achou = TRUE ;
        } else {
            i ++;
        }
    }
    
    return (achou) ;
}
int main () {
    // declaração de variavel
    int i ;
    // declaração de array
    int arint [] = {2 ,3 ,12 ,5 ,6 ,7 ,8 ,9 ,23 ,45};
    // If de verificação pertence retorna true, que por sua vez, depende de (madia(vetor),vetor)
    if (pertence(media(arint),arint)){
        printf ( "Media encontrada no vetor !\n" ) ;
    } 
    else {
        // resultado quando for falso
        printf ( "Media nao encontrada no vetor !\n " ) ;
    }
    getch (); // faz travar e esperar o pressionar de uma tecla qualquer de  <gconio>
}