#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor{
    public:
        static int nextId;
        int id;
        std::string telefone;
        bool avaliador;
        double lat;
        double lng;
        std::string nome;
        Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome); //construtor
};

#endif