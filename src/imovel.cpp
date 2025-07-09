#include "imovel.hpp"

int Imovel::nextId = 1; //Inicia o primeiro ID como 1

Imovel::Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco):
    tipo(parseTipo(tipoStr)), proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco){
        this->id = nextId++; //Incrementa o ID a cada corretor construído
} //Construtor

TipoImovel parseTipo(const std::string& tipoStr){ //Converte String para enum
    if(tipoStr == "Casa"){return TipoImovel::Casa;}
    else if(tipoStr == "Apartamento"){return TipoImovel::Apartamento;}
    else{return TipoImovel::Terreno;}
}

std::string Imovel::getTipoAsString() const {
    switch (tipo) {
        case TipoImovel::Casa: return "Casa";
        case TipoImovel::Apartamento: return "Apartamento";
        case TipoImovel::Terreno: return "Terreno";
        default: return "Desconhecido";
    }
}