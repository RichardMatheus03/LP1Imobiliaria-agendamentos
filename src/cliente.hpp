#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente{
    private:
        //Atributos privados
        int id;
        std::string telefone;
        std::string nome;
    public:
        //Métodos públicos
        Cliente(int id, std::string telefone, std::string nome); //Construtor
        //Getters e Setters Correspondentes
        int getId() const;
        std::string getTelefone() const;
        std::string getNome() const;
};

#endif