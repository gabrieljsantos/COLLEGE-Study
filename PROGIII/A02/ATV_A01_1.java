import java.util.Scanner;
public class ATV_A01_1 { // Definição 
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String frase;
        String [] pedaco;
        System.out.println("Digite uma frase: ");
        frase = sc.nextLine();
        
        pedaco = frase.split("");
        System.out.println("Quantidade de letras: " + pedaco.length);
        pedaco = frase.split(" ");
        System.out.println("Quantidade de palavras: " + pedaco.length);
        sc.close();
    }
}