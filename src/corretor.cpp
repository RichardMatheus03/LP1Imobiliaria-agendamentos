#include "corretor.hpp"
#include <iostream>

using namespace std;

int Corretor::nextId = 1; //Inicia o primeiro ID como 1

Corretor::Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome):
    telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome){
        this->id = nextId++; //Incrementa o ID a cada corretor construído
    }; //Construtor

std::string Corretor::getTelefone() const{
    return this->telefone;
}
int Corretor::getAvaliador() const{
    return this->avaliador;
}
double Corretor::getLat() const{
    return this->lat;
}
double Corretor::getLng() const{
    return this->lng;
}
std::string Corretor::getNome() const{
    return this->nome;
}
int Corretor::getId() const{
    return this->id;
}

void Corretor::addImovel(Imovel* imovel) {
    imoveis.push_back(imovel);
}

std::vector<Imovel*> Corretor::getImovelVector() const {
    return this->imoveis;
}

Corretor::Corretor() {
    this->id = nextId++; //Incrementa o ID a cada corretor construído
    this->telefone = "";
    this->avaliador = false;
    this->lat = 0.0;
    this->lng = 0.0;
    this->nome = "";
};

void Corretor::mostrarInfo() {
    cout << "ID: " << id << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Avaliador: " << (avaliador ? "Sim" : "Não") << std::endl;
    std::cout << "Latitude: " << lat << std::endl;
    std::cout << "Longitude: " << lng << std::endl;
    std::cout << "Nome: " << nome << std::endl;
} //Método para mostrar as informações do corretor