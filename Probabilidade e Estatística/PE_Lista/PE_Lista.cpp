#include <iostream>
using namespace std;

class ProbabilisticModel {
private:
    // Atributos (variáveis internas)
    int value;
    string Sets;

public:
    // Construtor
    ProbabilisticModel(int v) {
        value = v;
    }

    // Método (função membro)
    void show() {
        cout << "Valor: " << value << endl;
    }
};


int main() {
    ProbabilisticModel obj(10);   // Cria um objeto e chama o construtor
    obj.show();        // Usa um método público
    return 0;
}