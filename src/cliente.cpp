#include "cliente.hpp"

Cliente::Cliente(int id, std::string telefone, std::string nome):
    id(id), telefone(telefone), nome(nome){}; //Construtor

int Cliente::getId() const{
    return this->id;
}
void Cliente::setId(int input){
    this->id = input;
}
std::string Cliente::getTelefone() const{
    return this->telefone;
}
void Cliente::setTelefone(std::string& input){
    this->telefone = input;
}
std::string Cliente::getNome() const{
    return this->nome;
}
void Cliente::setNome(std::string& input){
    this->nome = input;
}