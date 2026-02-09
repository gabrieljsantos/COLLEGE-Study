#include <stdio.h>
// cd "d:\PROJECTS\COLLEGE-Study\PROGII\03 - Passagens de Parametros por Valor e por Referencia\" ; if ($?) { g++ PassagensdeParametrosVR.cpp -o PassagensdeParametrosVR } ; if ($?) { .\PassagensdeParametrosVR }

// ============================
// Exercício 1 — Cálculo Sustentável de Energia
// ============================
void calculoSustentavel(
    float solar, float eolica,
    float* total, float* diferenca,
    float* dobro_maior,
    float* porcentagem_solar, float* porcentagem_eolica,
    int* erro
) {
    if (solar < 0 || eolica < 0) {
        *erro = 1;
        return;
    }
    *erro = 0;
    *total = solar + eolica;

    // é um esquema que verrifica o maior e pega a diferença
    if (solar > eolica)
        *diferenca = solar - eolica;
    else
        *diferenca = eolica - solar;

    // Dobro da maior geração
    if (solar > eolica)
        *dobro_maior = 2 * solar;
    else
        *dobro_maior = 2 * eolica;

    *porcentagem_solar = (solar / *total) * 100;
    *porcentagem_eolica = (eolica / *total) * 100;
}

// ============================
// Exercício 2 — Comparação de Carros
// ============================
void compararCarros(
    float km_mes, float consumo_gasolina, float consumo_eletrico,
    float preco_gasolina, float preco_kwh, float co2_por_litro,
    float* custo_gasolina, float* custo_eletrico,
    float* emissao_co2, float* economia,
    float* reducao_emissao,
    int* erro
) {
    if (consumo_gasolina <= 0 || consumo_eletrico <= 0) {
        *erro = 1;
        return;
    }
    *erro = 0;
    *custo_gasolina = (km_mes / consumo_gasolina) * preco_gasolina * 12;
    *custo_eletrico = (km_mes / consumo_eletrico) * preco_kwh * 12;
    *emissao_co2 = (km_mes / consumo_gasolina) * co2_por_litro * 12;
    *economia = *custo_gasolina - *custo_eletrico;
    *reducao_emissao = 100; // carro elétrico não emite CO2
}

int main() {
    // ============================ Exercício 1 ============================
    float solar, eolica;
    printf("Digite a energia gerada pela usina solar (kWh): ");
    scanf("%f", &solar);
    printf("Digite a energia gerada pela usina eolica (kWh): ");
    scanf("%f", &eolica);

    float total, diferenca, dobro_maior, porcentagem_solar, porcentagem_eolica;
    int erro;

    calculoSustentavel(solar, eolica, &total, &diferenca, &dobro_maior,
                       &porcentagem_solar, &porcentagem_eolica, &erro);

    if (erro) {
        printf("Erro: Energia gerada não pode ser negativa!\n");
    } else {
        printf("\nRelatorio de Sustentabilidade\n########################################\n");
        printf("Total: %.2f kWh\n", total);
        printf("Diferenca: %.2f kWh\n", diferenca);
        printf("Dobro da maior: %.2f kWh\n", dobro_maior);
        printf("Porcentagem solar: %.2f%%\n", porcentagem_solar);
        printf("Porcentagem eolica: %.2f%%\n", porcentagem_eolica);
    }

    // ============================ Exercício 2 ============================
    float km_mes, consumo_gasolina, consumo_eletrico, preco_gasolina, preco_kwh, co2_por_litro;
    printf("\nDigite a quilometragem mensal (km): ");
    scanf("%f", &km_mes);
    printf("Digite o consumo do carro a gasolina (km/L): ");
    scanf("%f", &consumo_gasolina);
    printf("Digite o consumo do carro eletrico (km/kWh): ");
    scanf("%f", &consumo_eletrico);
    printf("Digite o preco da gasolina (R$): ");
    scanf("%f", &preco_gasolina);
    printf("Digite o preco do kWh (R$): ");
    scanf("%f", &preco_kwh);
    printf("Digite a emissao de CO2 por litro de gasolina (kg/L): ");
    scanf("%f", &co2_por_litro);

    float custo_gasolina, custo_eletrico, emissao_co2, economia, reducao_emissao;

    compararCarros(km_mes, consumo_gasolina, consumo_eletrico,
                   preco_gasolina, preco_kwh, co2_por_litro,
                   &custo_gasolina, &custo_eletrico,
                   &emissao_co2, &economia, &reducao_emissao,
                   &erro);

    if (erro) {
        printf("Erro: Os consumos dos veículos devem ser maiores que zero!\n");
    } else {
        printf("\nComparacao entre Carros a Gasolina e Eletricos\n########################################\n");
        printf("Custo anual gasolina: R$ %.2f\n", custo_gasolina);
        printf("Custo anual energia eletrica: R$ %.2f\n", custo_eletrico);
        printf("Emissoes CO2 gasolina: %.2f kg\n", emissao_co2);
        printf("Economia anual: R$ %.2f\n", economia);
        printf("Reducao de emissoes: %.2f%%\n", reducao_emissao);
    }

    return 0;
}
