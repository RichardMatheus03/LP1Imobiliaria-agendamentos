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
        int visitado = 0;
        int horaVisita = 0;
    public:
        //getters
        double getId() const;
        std::string getTipoAsString() const;
        int getProprietarioId() const;
        double getLat() const;
        double getLng() const;
        double getPreco() const;
        std::string getEndereco() const;
        void showInfo();
        int isVisitado() const;
        void visitar(int v);
        int getHoraVisita() const;
        void setHoraVisita(int input);

        Imovel(std::string tipoStr, int proprietarioId, double lat, double lng, double preco, std::string endereco); //Construtor
        Imovel(); //Construtor Padrão
};

TipoImovel parseTipo(const std::string& tipoStr); //Converte String para enum class

#endif