// cabeçalho para headers:
#ifndef ACIDENTE_H
#define ACIDENTE_H

struct acidente
{
    int id;
    char cidade[100];
    char estrada[100];
    char data[11]; //
    char diaSemana[10];
    char hora[6];
    char tipo[20];
    int Nmortos;
    int Nferidos;
    char descricao[200];
};

#endif // ACIDENTE_H