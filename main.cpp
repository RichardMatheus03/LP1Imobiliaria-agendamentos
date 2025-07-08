#include <iostream>
#include "leitura.h"

using namespace std;

int main() {

    /*int numCorretores;
    std::cin >> numCorretores;

    for (int i = 0; i < numCorretores; i++) {
        cout << "Corretor " << i << ": ";   
    }*/

    //teste de leitura
    auto corretores = lerCorretores();
    auto clientes = lerClientes();
    auto imoveis = lerImoveis();

    std::cout << "Corretores lidos: " << corretores.size() << std::endl;
    std::cout << "Clientes lidos: " << clientes.size() << std::endl;
    std::cout << "Imóveis lidos: " << imoveis.size() << std::endl;

    return 0;
}