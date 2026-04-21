import java.util.Arrays; // Importa utilitário para imprimir arrays
import java.util.Random;
import java.util.Scanner; // Importa a classe Scanner para ler entrada do usuário

public class ATV_A02_1 { // Definição da classe, por orbirgação do nome do arquivo

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // declarando um instancia de nome sc da classe Scanner do tipo entrada
        int N_produto = 4;
        int N_prateleiras = 4; 
        int m[][] = new int[N_produto][N_prateleiras]; // primeiro declarando uma instancia matriz do tipo inteiro, e definindo a ela uma matriz do tipo intero [4][4]
        Boolean indicador10[] = new Boolean[N_prateleiras]; // declarando um vetor do tipo inteiro, e definindo a ela um vetor do tipo inteiro [4]
        int menor = 1000;
        int index_menor = -1;
        int indey_menor = -1;


        for (int i = 0; i < N_prateleiras; i++) {
            for (int j = 0; j < N_produto; j++) {
                m[j][i] = new Random().nextInt(5); // Gerando um numero aleatório entre 0 e 4 para preencher a matriz
            }
            
        }

        for (int i = 0; i < N_prateleiras; i++) {
            for (int j = 0; j < N_produto; j++) {
                if (m[i][j] < menor) {
                    menor = m[i][j];
                    index_menor = i;
                    indey_menor = j;
                }
                System.out.print(m[i][j] + " | "); // Imprime o valor gerado para cada posição da matriz");
            }
            System.out.println("");
            
        }
        for (int i = 0; i < N_prateleiras; i++) {
            int sum = 0;
            for (int j = 0; j < N_produto; j++) {
                sum += m[j][i];
            }
            indicador10[i] = sum > 10;
        }
        
        for (int i = 0; i < N_prateleiras; i++) {
            if (indicador10[i]) {
                System.out.println("Prateleira " + i + " tem mais de 10 produtos.");
            }
        }
        System.out.println("Menor valor: " + menor + " na posição (" + index_menor + ", " + indey_menor + ")");

    }
}