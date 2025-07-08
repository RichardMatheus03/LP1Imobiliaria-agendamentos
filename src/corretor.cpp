#include "corretor.hpp"

int Corretor::nextId = 1; //Inicia o primeiro ID como 1

Corretor::Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome):
    telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome){
        this->id = nextId++; //Incrementa o ID a cada corretor construído
} //Construtor
