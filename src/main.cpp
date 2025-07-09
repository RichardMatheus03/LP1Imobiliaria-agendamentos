#include <iostream>
#include <iomanip> //para setprecision
#include "leitura.hpp"
#include "utilitarios.cpp"

using namespace std;

int main() {

    auto corretores = lerCorretores();
    auto clientes = lerClientes();
    auto imoveis = lerImoveis();

    std::vector<Corretor> corretoresAvaliadores = filtrarCorretoresAvaliadores(corretores);

    for (size_t i = 0; i < corretoresAvaliadores.size(); ++i) {
        
        // Para cada avaliador
        Corretor& corretorAvaliador = corretoresAvaliadores[i];

        Imovel imovelMaisProximo = encontrarImovelMaisProximo(corretorAvaliador, imoveis);

    }

    return 0;
}