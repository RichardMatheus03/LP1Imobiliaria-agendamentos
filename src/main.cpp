#include <iostream>
#include <iomanip> //para setprecision
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