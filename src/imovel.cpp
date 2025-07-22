#include "imovel.hpp"

#include <iostream>


int Imovel::nextId = 1; //Inicia o primeiro ID como 1

Imovel::Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco):
    tipo(parseTipo(tipoStr)), proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco){
        this->id = nextId++; //Incrementa o ID a cada corretor construído
        this->horaVisita = 0;
        this->visitado = false;
} //Construtor

TipoImovel parseTipo(const std::string& tipoStr){ //Converte String para enum
    if(tipoStr == "Casa") {
        return TipoImovel::Casa;
    }
    else if(tipoStr == "Apartamento") {
        return TipoImovel::Apartamento;
    }
    else {
        return TipoImovel::Terreno;
    }
}

std::string Imovel::getTipoAsString() const {
    switch (tipo) {
        case TipoImovel::Casa: return "Casa";
        case TipoImovel::Apartamento: return "Apartamento";
        case TipoImovel::Terreno: return "Terreno";
        default: return "Desconhecido";
    }
}
double Imovel::getId() const{
    return this->id;
}
int Imovel::getProprietarioId() const{
    return this->proprietarioId;
}
double Imovel::getLat() const{
    return this->lat;
}
double Imovel::getLng() const{
    return this->lng;
}
double Imovel::getPreco() const{
    return this->preco;
}
std::string Imovel::getEndereco() const{
    return this->endereco;
}
void Imovel::visitar(bool input){
    this->visitado = input;
}
bool Imovel::isVisitado() const{
    return this->visitado;
}
void Imovel::setHoraVisita(int input){
    this->horaVisita = input;
}
int Imovel::getHoraVisita(){
    return this->horaVisita;
}

Imovel::Imovel(){
    this->tipo = TipoImovel::Casa;
    this->proprietarioId = 0;
    this->lat = 0.0;
    this->lng = 0.0;
    this->preco = 0;
    this->endereco = "";
};

void Imovel::showInfo() {
    std::cout << "ID: " << id << "\n"
              << "Tipo: " << getTipoAsString() << "\n"
              << "Proprietário ID: " << proprietarioId << "\n"
              << "Localização: (" << lat << ", " << lng << ")\n"
              << "Preço: R$" << preco << "\n"
              << "Endereço: " << endereco << std::endl;
};