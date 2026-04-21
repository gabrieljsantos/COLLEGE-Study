// Gabriel J Santos

public class Contas {

    String nome;
    String tipo_da_conta;
    int numero_da_conta;
    double saldo;

    // Construtor
    public Contas(String nome, String tipo_da_conta, int numero_da_conta, double saldo) {
        this.nome = nome;
        this.tipo_da_conta = tipo_da_conta;
        this.numero_da_conta = numero_da_conta;
        this.saldo = saldo;
    }
    // metodo para sacar
    public void sacar(double valor) {
        if (saldo >= valor) {
            saldo -= valor;
            System.out.println("Saque realizado com sucesso. Novo saldo: " + saldo);
        } else {
            System.out.println("Saldo insuficiente para realizar o saque.");
        }
    }
    // metodo para depositar
    public void depositar(double valor) {
        saldo += valor;
        System.out.println("Depósito realizado com sucesso. Novo saldo: " + saldo);
    }
    // metodo para imprimir os dados da conta
    public void imprimir() {
        System.out.println("Nome do Cliente: " + nome);
        System.out.println("Tipo da Conta: " + tipo_da_conta);
        System.out.println("Número da Conta: " + numero_da_conta);
        System.out.println("Saldo: " + saldo);
    }

}