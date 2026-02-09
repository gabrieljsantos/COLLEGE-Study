#include <iostream>

using namespace std;

struct Filme {
    string titulo;
    string genero;
    int duracaoMIn;
    float precoIngresso;
    int ingressosVendidos;
    float arrecadacao;
};

float calcularArrecadacao(Filme f){
    float arrecadacao = f.ingressosVendidos * f.precoIngresso;
    return arrecadacao;
}

float calcularArrecadacao(Filme filmes[], int n){
    float total = 0;
    for (int i = 0 ; i <= n; i++){
        total += filmes[i].arrecadacao;
    }
    return total;
}


void printMenu(){
    system("CLS");
    cout << "############### MENU ###############" << endl;
    cout << "[1] Cadastrar novo filme" << endl;
    cout << "[2] Listar todos os filmes" << endl;
    cout << "[3] Exibir filme com maior arrecadacao" << endl;
    cout << "[4] Calcular arrecadacao total" << endl << endl;

}
void cadastrarFilme(Filme& f){
    system("CLS");
    cout << "####### CADASTRAR NOVO FILME #######" << endl;
    cout << " Titulo: ";
    cin >> f.titulo;
    cout << " Genero:" ;
    cin >> f.genero;
    cout << " Duracao:";
    cin >> f.duracaoMIn;
    cout << " Preco ingresso: ";
    cin >> f.precoIngresso;
    cout << " Ingressos vendidos: ";
    cin >> f.ingressosVendidos;
    cout << " Arrecadacao: R$ " ;
    f.arrecadacao = calcularArrecadacao(f);
    cout << f.arrecadacao << endl << endl << endl ;

    system("pause");
    cout << " FILME CADASTRADO " ;
}

void exibirFilme(const Filme &f){
    cout << " Titulo : " << f.titulo << endl;
    cout << " Genero : " << f.genero << endl;
    cout << " Duracao : " << f.duracaoMIn << endl;
    cout << " Preco ingresso : " << f.precoIngresso << endl;
    cout << " Ingressos vendidos : " << f.ingressosVendidos << endl;
    cout << " Arrecadacao: R$ : " << f.arrecadacao << endl;


}


int indiceMaiorArrecadacao(Filme filmes[], int n){
    int index_max = 0;
    float last_maxArrcdc = 0;
    for (int i = 0 ; i < n; i++){
        if (filmes[i].arrecadacao > last_maxArrcdc){
            last_maxArrcdc = filmes[i].arrecadacao;
            index_max = i;
        }
    }
    return index_max;
}


int main()
{
    Filme Filmes[10];
    bool run = 1;
    int request = 0;
    int index_qtd = 0;
    while(run){
        printMenu();
        cout <<  "Digite  a Opcao   : ";
        cin >> request;
        switch (request){
        case 1:
            cadastrarFilme(Filmes[index_qtd]);
            index_qtd++;
            break;
        case 2:

            system("CLS");
            cout << "######### LISTA DE FILMES #########" << endl;
            for (int i = 0 ; i < index_qtd; i++){
                //cout << i << endl;
                exibirFilme(Filmes[i]);
                cout << endl << "=================================== " << endl << endl;
            }
            system("pause");
            break;
        case 3:

            system("CLS");
            cout << "### FILME DE MAIOR ARRECADAÇÃO ###" << endl;

            exibirFilme(Filmes[indiceMaiorArrecadacao(Filmes,index_qtd)]);

            system("pause");
            break;
        case 4:

            system("CLS");
            cout << "####### ARRECADAÇÃO TOTAL #######" << endl;

            cout << " TOTAL : R$ : " << calcularArrecadacao(Filmes, index_qtd) << endl;
            system("pause");
            break;
        default:
            cout << "Saindo ...." << endl;
            return 0;
        }
    }

    return 0;
}
