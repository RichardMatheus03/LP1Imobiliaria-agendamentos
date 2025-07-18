// Esse arquivo contém funções utilitárias para o sistema no geral
// Que serão usadas principalmente no main, para não deixar o arquivo poluído
// e também para facilitar a manutenção do código, separamos as funções

#include <cmath>
#include <vector>
#include "corretor.hpp"
#include "imovel.hpp"

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

std::vector<Corretor> filtrarCorretoresAvaliadores(const std::vector<Corretor>& corretores) {

    std::vector<Corretor> avaliadores;

    for (size_t i = 0; i < corretores.size(); ++i) {
        if (corretores[i].getAvaliador()) {
            avaliadores.push_back(corretores[i]);
        }
    }

    return avaliadores;

}

Imovel encontrarImovelMaisProximo(const Corretor& corretor, const std::vector<Imovel>& imoveis) {
    
    double menorDistancia = 9*10^9; //É necessário inicializar a variável com algum valor
    Imovel imovelMaisProximo;
    
    for (size_t i = 0; i < imoveis.size(); ++i) {
        
        double distancia = haversine(corretor.getLat(), corretor.getLng(), imoveis[i].getLat(), imoveis[i].getLng());

        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            imovelMaisProximo = imoveis[i];
        }

    }

    return imovelMaisProximo;

};

std::vector<Imovel> pegarImoveisDesseCorretor(Corretor corretor){
    int id = corretor.getId();
    
}