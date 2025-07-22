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

        //Agendamento
        unsigned int horaAtual = 540;
        double latAtual = corretorAvaliador.getLat();
        double lngAtual = corretorAvaliador.getLng();
        while(true){
            Imovel* imovelAtual = encontrarImovelMaisProximo(latAtual, lngAtual, imoveisDesseCorretor);
            if (imovelAtual == nullptr) break;

            double distancia = 2.000 * haversine(latAtual, lngAtual, imovelAtual->getLat(), imovelAtual->getLng());
            int tempoDeslocamento = distancia; 
            horaAtual += tempoDeslocamento;

            imovelAtual->setHoraVisita(horaAtual);
            imovelAtual->visitar(true);

            latAtual = imovelAtual->getLat();
            lngAtual = imovelAtual->getLng();

            horaAtual += 60;
        }

        std::cout << "Corretor " << corretorAvaliador.getId() << endl;
        for (size_t j = 0; j < imoveisDesseCorretor.size(); ++j){
            // conversão da hara
            int hora = imoveisDesseCorretor[j]->getHoraVisita() / 60;
            int minuto = imoveisDesseCorretor[j]->getHoraVisita() % 60;
            std::cout << std::setfill('0') << std::setw(2) << hora << ":" << std::setw(2)
                      << minuto << " Imóvel " << imoveisDesseCorretor[j]->getId();

            if(j < imoveisDesseCorretor.size() - 1){
                std::cout << endl;
            }
        }

        if(i < corretoresAvaliadores.size() - 1){
            std::cout << endl << endl;
        }

    }

    return 0;
}