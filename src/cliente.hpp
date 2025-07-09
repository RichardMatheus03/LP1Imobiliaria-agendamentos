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
        void setId(int input);
        std::string getTelefone() const;
        void setTelefone(std::string& input);
        std::string getNome() const;
        void setNome(std::string& input);
};

#endif