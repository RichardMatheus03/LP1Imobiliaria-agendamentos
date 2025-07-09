#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

enum class TipoImovel{Casa, Apartamento, Terreno}; //Enumeradores

class Imovel{
    public:
        static int nextId;
        int id;
        TipoImovel tipo;
        int proprietarioId;
        double lat, lng;
        double preco;
        std::string endereco;

        Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco);
        
        std::string getTipoAsString() const;
};

TipoImovel parseTipo(const std::string& tipoStr); //Converte String para enum class

#endif

