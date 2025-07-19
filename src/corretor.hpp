#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>
#include <vector>
#include "imovel.hpp"

class Corretor{
    private:
        static int nextId;
        int id;
        std::string telefone;
        bool avaliador;
        double lat;
        double lng;
        std::string nome;
        std::vector<Imovel*> imoveis;

    public:
        std::string getTelefone() const;
        int getAvaliador() const;
        double getLat() const;
        double getLng() const;
        std::string getNome() const;
        int getId() const;
        void addImovel(Imovel* imovel);
        std::vector<Imovel*> getImovelVector() const;

        // Construtor
        Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome); //construtor
        Corretor(); // Contrutor padrão
        
        //Métodos
        void mostrarInfo();
};

#endif