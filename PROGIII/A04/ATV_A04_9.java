/*Implemente uma classe Carro para gerenciar as informações individuais e estatísticas globais da
frota
Essa classe deve conter:
Atributos de instancia: modelo e quilometragem
Atributos estáticos: totalCarros e metaQuilometragem
Métod
Constrer que incremente o totalCarros toda ver que um novo carro for instanciado
Método destância chamado rodar (double km): adiciona quilometragem ao carro especifico.
Método estat chamado alterarMeta(double novaMeta) muda a meta de todos os carros de
Luma ver */


public class ATV_A04_9{

    public static void main(String[] args) {
        Contas conta1 = new Contas("Gabriel J Santos", "Corrente", 12345, 1000.00);
        conta1.imprimir();
        conta1.depositar(500.00);
        conta1.sacar(200.00);
        conta1.imprimir();
    }

}