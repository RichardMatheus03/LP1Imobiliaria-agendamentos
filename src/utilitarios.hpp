#ifndef UTILITARIOS_HPP
#define UTILITARIOS_HPP

// Esse arquivo contém funções utilitárias para o sistema no geral
// Que serão usadas principalmente no main, para não deixar o arquivo poluído
// e também para facilitar a manutenção do código, separamos as funções

#include <cmath>
#include <vector>
#include "corretor.hpp"
#include "imovel.hpp"

double haversine(double lat1, double lon1, double lat2, double lon2);

std::vector<Corretor> filtrarCorretoresAvaliadores(const std::vector<Corretor>& corretores);

Imovel* encontrarImovelMaisProximo(double lat, double lng, const std::vector<Imovel*>& imoveis);

#endif