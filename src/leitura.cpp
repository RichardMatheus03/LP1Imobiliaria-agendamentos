#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "leitura.hpp"

std::vector<Corretor> lerCorretores(){
    int n;
    std::cin >> n;
    std::vector<Corretor> corretores;

    for (int i=0; i<n; ++i){
        std::string telefone; int avaliador; double lat, lng;
        std::cin >> telefone >> avaliador >> lat >> lng;
        std::string nome;
        std::getline(std::cin >> std::ws, nome);
        corretores.emplace_back(telefone, avaliador, lat, lng, nome);
    }

    return corretores;
}

std::vector<Cliente> lerClientes(){
    int n;
    std::cin >> n;
    std::vector<Cliente> clientes;

    for (int i=0; i<n; ++i){
        std::string telefone;
        std::string nome;
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);
        clientes.emplace_back(i + 1, telefone, nome);
    }

    return clientes;
}

std::vector<Imovel> lerImoveis(){
    int n;
    std::cin >> n;
    std::vector<Imovel> imoveis;

    for (int i=0; i<n; ++i){
        std::string tipo;
        int propId;
        double lat, lng, preco;
        std::cin >> tipo >> propId >> lat >> lng >> preco;
        std::string endereco;
        std::getline(std::cin >> std::ws, endereco);
        imoveis.emplace_back(tipo, propId, lat, lng, preco, endereco);
    }

    return imoveis;
}