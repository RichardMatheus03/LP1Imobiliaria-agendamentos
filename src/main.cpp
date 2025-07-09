#include <iostream>
#include "leitura.hpp"

using namespace std;

std::vector<Corretor> filtrarCorretoresAvaliadores(const std::vector<Corretor>& corretores) {
    std::vector<Corretor> avaliadores;

    for (int i = 0; i < corretores.size(); ++i) {
        if (corretores[i].avaliador) {
            avaliadores.push_back(corretores[i]);
        }
    }
    return avaliadores;
}

int main() {

    auto corretores = lerCorretores();
    auto clientes = lerClientes();
    auto imoveis = lerImoveis();

    std::vector<Corretor> corretoresAvaliadores = filtrarCorretoresAvaliadores(corretores);

    

    std::cout << "Corretores lidos: " << corretores.size() << std::endl;
    std::cout << "Clientes lidos: " << clientes.size() << std::endl;
    std::cout << "Imóveis lidos: " << imoveis.size() << std::endl;

    return 0;
}