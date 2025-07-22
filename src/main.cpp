#include <iostream>
#include <iomanip> //para setprecision
#include "leitura.hpp"
#include "utilitarios.hpp"

using namespace std;

int main() {

    auto corretores = lerCorretores();
    auto clientes = lerClientes();
    auto imoveis = lerImoveis();

    for (auto& imovel : imoveis) {
    std::cout << "ID: " << imovel.getId() << std::endl;
}

    std::vector<Corretor*> corretoresAvaliadores = filtrarCorretoresAvaliadores(corretores);

    //Separando imóveis para cada corretor (round-robin)
    for (size_t i = 0; i < imoveis.size(); ++i){
        size_t j = i % corretoresAvaliadores.size(); //% = resto da divisão inteira
        corretoresAvaliadores[j]->addImovel(&imoveis[i]);
    }

    for (size_t i = 0; i < corretoresAvaliadores.size(); ++i) {
        
        //Para cada avaliador
        Corretor* corretorAvaliador = corretoresAvaliadores[i];
        
        //Vector de imóveis do corretor
        std::vector<Imovel*> imoveisDesseCorretor = corretorAvaliador->getImovelVector();

        //Agendamento
        /*unsigned int horaAtual = 9 * 60;;
        double latAtual = corretorAvaliador->getLat();
        double lngAtual = corretorAvaliador->getLng();
        while(true){
            Imovel* imovelAtual = encontrarImovelMaisProximo(latAtual, lngAtual, imoveisDesseCorretor);
            if (imovelAtual == nullptr) break;

            double distancia = haversine(latAtual, lngAtual, imovelAtual->getLat(), imovelAtual->getLng());
            int tempoDeslocamento = static_cast<int>(round(2.0 * distancia));
            horaAtual += tempoDeslocamento;

            imovelAtual->setHoraVisita(horaAtual);
            imovelAtual->visitar(true);

            latAtual = imovelAtual->getLat();
            lngAtual = imovelAtual->getLng();

            horaAtual += 60;
        }*/

        //impressão
        std::cout << "Corretor " << corretorAvaliador->getId() << endl;
        for (size_t j = 0; j < imoveisDesseCorretor.size(); ++j){
            std::cout << imoveisDesseCorretor[j]->getHoraVisita() << " Imóvel: " << imoveisDesseCorretor[j]->getId() << endl;
        }

        std::cout << endl << "----------------------------------------" << endl << endl;

        imoveisDesseCorretor.clear();

    }

    return 0;
}
