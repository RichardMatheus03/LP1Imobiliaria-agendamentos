#include <iostream>
#include <iomanip> //para setprecision
#include "leitura.hpp"

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

    //Imprime as informações
    std::cout << "Corretores lidos: " << corretores.size() << "\n";
    for (const auto& c : corretores) {
        std::cout << "    " << c.getTelefone() << " " << c.getAvaliador() << " " << c.getLat() << " " << c.getLng() << " " << c.getNome() << "\n";
    }

    std::cout << "Clientes lidos: " << clientes.size() << "\n";
    for (const auto& cl : clientes) {
        std::cout << "    " << cl.getTelefone() << " " << cl.getNome() << "\n";
    }

    std::cout << "Imóveis lidos: " << imoveis.size() << "\n";
    for (const auto& im : imoveis) {
        std::cout << "    " << im.getTipoAsString() << " " << im.proprietarioId << " " << im.lat << " " << im.lng << " " << std::fixed << std::setprecision(2) << im.preco << " " << im.endereco << "\n";
    }
    return 0;
}