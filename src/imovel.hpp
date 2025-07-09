#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

enum class TipoImovel{Casa, Apartamento, Terreno}; //Enumeradores

class Imovel{
    private:
        static int nextId;
        int id;
        TipoImovel tipo;
        int proprietarioId;
        double lat, lng;
        double preco;
        std::string endereco;
    public:
        //getters
        std::string getTipoAsString() const;
        int Imovel::getProprietarioId() const;
        double Imovel::getLat() const;
        double Imovel::getLng() const;
        double Imovel::getPreco() const;
        std::string Imovel::getEndereco() const;

        Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco); //Construtor
        Imovel(); //Construtor Padrão
};

TipoImovel parseTipo(const std::string& tipoStr); //Converte String para enum class

#endif

