#include <iostream>
#include <iomanip> //para setprecision
#include "leitura.hpp"
#include "utilitarios.hpp"

using namespace std;

int main() {

    auto corretores = lerCorretores();
    auto clientes = lerClientes();
    auto imoveis = lerImoveis();

    std::vector<Corretor> corretoresAvaliadores = filtrarCorretoresAvaliadores(corretores);

    for (size_t i = 0; i < corretoresAvaliadores.size(); ++i) {
        
        // Para cada avaliador
        Corretor& corretorAvaliador = corretoresAvaliadores[i];
        
        //Separando imoveis para cada corretor
        std::vector<Imovel> imoveisDesseCorretor;
        for (size_t i = 0; i < imoveis.size(); ++i) {
            if (imoveis[i].getProprietarioId() == corretorAvaliador.getId()) {
                imoveisDesseCorretor.push_back(imoveis[i]);
            }
        }
        
        Imovel imovelMaisProximo = encontrarImovelMaisProximo(corretorAvaliador, imoveisDesseCorretor);  
        
        cout << "Corretor: " << corretorAvaliador.getNome() << endl;
        cout << "id: " << corretorAvaliador.getId() << endl;

        cout << "----------------------------------------" << endl;

        for (size_t i = 0; i < imoveisDesseCorretor.size(); ++i) {
            imoveisDesseCorretor[i].showInfo();
        }

        cout << "----------------------------------------" << endl;

        cout << "Imóvel mais próximo: " << endl;
        imovelMaisProximo.showInfo();

        cout << "----------------------------------------" << endl;

    }

    return 0;
}
