import java.util.Arrays; // Importa utilitário para imprimir arrays

public class ATV_A01_2 { // Definição da classe, por orbirgação do nome do arquivo

    public static void main(String[] args) {
        // public static void main(String[] args) é a forma de declarar um método estático

        // Vetor de leituras do sensor (dados de entrada)
        double[] leituras = {10.0, 12.0, 15.0, 18.0, 20.0, 22.0};

        // Tamanho da janela da média móvel
        int k = 3;

        // Verifica se o vetor possui tamanho suficiente para aplicar a média móvel
        if (leituras.length < k) {
            // Caso não seja possível processar
            System.out.println("Não é possível processar o vetor: tamanho menor que K.");
            return; // Encerra o programa
        }

        // Calcula o tamanho do vetor resultante (n - k + 1)
        int tamanho_resultado = leituras.length - k + 1;

        // Cria o vetor que armazenará as médias
        double[] medias = new double[tamanho_resultado];

        // Loop principal para calcular as médias móveis
        for (int i = 0; i < tamanho_resultado; i++) {

            // Variável acumuladora para somar os elementos da janela
            double soma = 0.0;

            // Loop interno para percorrer os K elementos da janela
            for (int j = 0; j < k; j++) {

                // Soma os valores dentro da janela (i até i + k - 1)
                soma += leituras[i + j];
            }

            // Calcula a média da janela atual
            double media = soma / k;

            // Armazena a média no vetor resultado
            medias[i] = media;
        }

        // Impressão do vetor original
        System.out.println("Leituras: " + Arrays.toString(leituras));

        // Impressão do vetor de médias móveis
        System.out.println("Médias móveis: " + Arrays.toString(medias));
    }
}