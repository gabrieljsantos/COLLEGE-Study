class Pessoa {
	private String nome;
	private int idade;
	private String cpf;

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public void fazerAniversario() {
		idade++;
	}

	public boolean ehMaiorDeIdade() {
		return idade >= 18;
	}

	public void imprimirDados() {
		System.out.println("Nome: " + nome);
		System.out.println("Idade: " + idade);
		System.out.println("CPF: " + cpf);
	}
}

public class exer1 {
	public static void main(String[] args) {
		Pessoa pessoa = new Pessoa();

		pessoa.setNome("Maria Silva");
		pessoa.setIdade(20);
		pessoa.setCpf("123.456.789-00");

		System.out.println("Dados da pessoa:");
		pessoa.imprimirDados();
		System.out.println("Maior de idade: " + pessoa.ehMaiorDeIdade());

		pessoa.fazerAniversario();
		System.out.println("\nDepois de fazer aniversario:");
		pessoa.imprimirDados();

		System.out.println("\nAcesso pelos getters:");
		System.out.println("Nome: " + pessoa.getNome());
		System.out.println("Idade: " + pessoa.getIdade());
		System.out.println("CPF: " + pessoa.getCpf());
	}
}