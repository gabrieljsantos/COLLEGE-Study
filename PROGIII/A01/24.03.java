/*escreva um algoritmo que receba como entrada o preço de um produto informado pelo
usuario, calcula o novo preço desse produto com desconto de 9% e imprime o resultado
*/ 

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Preço do produto: ");
		double preco = sc.nextDouble();
		double novopreco = preco - (preco * 0.09);
		System.out.println("Novo preço do produto: " + novopreco);
	}

}   

/* escreva um algoritmo que leia  as 3 motas de u alçuno e calcule a
sua media final. paea calculo consisdere que media a ser calculada é
a ponderada e que o peso das notas é: 2 , 3 e 5, respectivamente.
*/

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite a primeira nota: ");
		int nota1 = sc.nextInt();
		System.out.println("Digite a segunda nota: ");
		int nota2 = sc.nextInt();
		System.out.println("Digite a terceira nota: ");
		int nota3 = sc.nextInt();
		double media = (nota1 * 2) + (nota2 * 3) + (nota3 * 5);
		media = media / 10;
		System.out.println("Sua media final é: " + media);
	}

}


/*
Implemente um programa em java que recebe uma palavra e uma letra d
*/