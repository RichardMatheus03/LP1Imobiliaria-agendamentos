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
        double getId() const;
        std::string getTipoAsString() const;
        int getProprietarioId() const;
        double getLat() const;
        double getLng() const;
        double getPreco() const;
        std::string getEndereco() const;

        Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco); //Construtor
        Imovel(); //Construtor Padrão
};

TipoImovel parseTipo(const std::string& tipoStr); //Converte String para enum class

#endif

