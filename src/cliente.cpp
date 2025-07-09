#include "cliente.hpp"

Cliente::Cliente(int id, std::string telefone, std::string nome):
    id(id), telefone(telefone), nome(nome){}; //Construtor

int Cliente::getId() const{
    return this->id;
}
std::string Cliente::getTelefone() const{
    return this->telefone;
}
std::string Cliente::getNome() const{
    return this->nome;
}