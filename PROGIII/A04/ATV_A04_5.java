/* Escreva uma classe Java para representar as contas dos clientes de um banco. Essa classe deve conter os seguintes atributos:
1. Tipo da conta (corrente, poupança ou salário)
2. Número da conta
3. Nome do Cliente
4. Saldo
Essa conta deve conter os seguintes métodos (além de 2 construtores e os métodos de cesso aos atributos):
Sacar (valor): verifica se a conta tem saldo e subtrai o valor a ser sacado do salo atual
Depositar (valor): adiciona o valor passado por parâmetro ao saldo;
Imprimir(): imprime todos os dados da conta. */



public class ATV_A04_5 {

    public static void main(String[] args) {
        Contas conta1 = new Contas("Gabriel J Santos", "Corrente", 12345, 1000.00);
        conta1.imprimir();
        conta1.depositar(500.00);
        conta1.sacar(200.00);
        conta1.imprimir();
    }

}