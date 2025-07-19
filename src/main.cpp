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

    //Separando imóveis para cada corretor (round-robin)
    for (size_t i = 0; i < imoveis.size(); ++i){
        size_t j = i % corretoresAvaliadores.size(); //% = resto da divisão inteira
        corretoresAvaliadores[j].addImovel(&imoveis[i]);
    }

    for (size_t i = 0; i < corretoresAvaliadores.size(); ++i) {
        
        //Para cada avaliador
        Corretor corretorAvaliador = corretoresAvaliadores[i];
        
        //Vector de imóveis do corretor
        std::vector<Imovel*> imoveisDesseCorretor = corretorAvaliador.getImovelVector();

        std::cout << "Corretor " << corretorAvaliador.getId() << endl;
        for (size_t j = 0; j < imoveisDesseCorretor.size(); ++j){
            std::cout << "    " << "Imóvel: " << imoveisDesseCorretor[j]->getId() << endl;
        }

        std::cout << endl << "----------------------------------------" << endl << endl;

        
        /*Imovel* imovelMaisProximo = encontrarImovelMaisProximo(corretorAvaliador, imoveisDesseCorretor);  
        
        std::cout << "Corretor: " << corretorAvaliador.getNome() << endl;
        std::cout << "id: " << corretorAvaliador.getId() << endl;

        std::cout << "----------------------------------------" << endl;

        for (size_t i = 0; i < imoveisDesseCorretor.size(); ++i) {
            imoveisDesseCorretor[i]->showInfo();
        }

        std::cout << "----------------------------------------" << endl;

        std::cout << "Imóvel mais próximo: " << endl;
        imovelMaisProximo->showInfo();

        std::cout << "----------------------------------------" << endl;*/

    }

    return 0;
}
