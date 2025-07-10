#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor{
    private:
        static int nextId;
        int id;
        std::string telefone;
        bool avaliador;
        double lat;
        double lng;
        std::string nome;

    public:
        std::string getTelefone() const;
        int getAvaliador() const;
        double getLat() const;
        double getLng() const;
        std::string getNome() const;
        
        // Construtor
        Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome); //construtor
        Corretor(); // Contrutor padrão
        
        //Métodos
        void mostrarInfo();
};

#endif