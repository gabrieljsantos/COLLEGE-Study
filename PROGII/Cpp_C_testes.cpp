#include <stdio.h>

int main(void) {
    printf("Código ASCII - Decimal | Hexadecimal | Caractere\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i <= 127; i++) {
        printf("%3d               | 0x%02X       | %c\n", i, i, i);
    }
    /*
    %3d imprime o número decimal de i com largura mínima de 3 caracteres,alinhando à direita;
    0x%02X imprime o número em hexadecimal usando duas casas,
    %c converte o valor de i para o caractere ASCII correspondente,
    */
    return 0;
}