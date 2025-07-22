// Esse arquivo contém funções utilitárias para o sistema no geral
// Que serão usadas principalmente no main, para não deixar o arquivo poluído
// e também para facilitar a manutenção do código, separamos as funções

#include <cmath>
#include <vector>
#include "corretor.hpp"
#include "imovel.hpp"

#include <iostream>
using namespace std;

constexpr double EARTH_R = 6371.0; // Raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

std::vector<Corretor*> filtrarCorretoresAvaliadores(std::vector<Corretor>& corretores) {

    std::vector<Corretor*> avaliadores;

    for (size_t i = 0; i < corretores.size(); ++i) {
        if (corretores[i].getAvaliador()) {
            avaliadores.push_back(&corretores[i]);
        }
    }

    return avaliadores;

}

//Retorna o imóvel mais próximo *não visitado*
Imovel* encontrarImovelMaisProximo(double lat, double lng, const std::vector<Imovel*>& imoveis) {
    
    double menorDistancia = 1e9; //É necessário inicializar a variável com algum valor. 
    Imovel* imovelMaisProximo = nullptr;
    
    for (size_t i = 0; i < imoveis.size(); ++i) {
        if(imoveis[i]->isVisitado() == false){
            double distancia = haversine(lat, lng, imoveis[i]->getLat(), imoveis[i]->getLng());
            
            cout << "Distância em km " << distancia << endl;
            
            if ((distancia < menorDistancia)) {
                menorDistancia = distancia;
                imovelMaisProximo = imoveis[i];
            }
        }
    }

    return imovelMaisProximo;

};

// Adicionar hora ao agendamento
/*int horaAtual = 9 * 60;
int tempoDeslocamento = round(menorDistancia * 2.0);
    horaAtual += tempoDeslocamento;

            // conversão da hara
            int hora = horaAtual / 60;
            int minuto = horaAtual % 60;
            std::cout << std::setfill('0') << std::setw(2) << hora << ":"
                      << std::setw(2) << minuto << " Imóvel " << imovelEscolhido->getId() << std::endl;

            // atualização de local do corretor
            pontoAtualLat = imovelEscolhido->getLat();
            pontoAtualLon = imovelEscolhido->getLng();
            horaAtual += 60;*/
