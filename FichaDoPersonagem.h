#ifndef PROJETO_R_FICHADOPERSONAGEM_H
#define PROJETO_R_FICHADOPERSONAGEM_H

#include "Util.h"
#include "GeradorDeTelas.h"

class FichaDoPersonagem {
private:
    GeradorDeTelas geradorDeTelas;

    string NOME;
    float VIDA;
    float FORCA;
    float SABEDORIA;

    void setVida(float vida);
    void setForca(float forca);
    void setSabedoria(float sabedoria);

public:
    FichaDoPersonagem();

    FichaDoPersonagem(const string &nome);

    void setGeradorDeTelas(const GeradorDeTelas &geradorDeTelas);

    void setNome(const string &nome);

    const string &getNome() const;
    float getVida() const;
    float getForca() const;
    float getSabedoria() const;

    void mostrarFichaDoPersonagem();
    bool modificador(string caracteristica, int valor);

    bool aplicaPositivaVital(string caracteristica);
    bool aplicaPositiva(string caracteristica);
    bool aplicaNegativa(string caracteristica);
    bool aplicaNegativaVital(string caracteristica);

    void aplicarModificador(string caracteristica, float valor);

    string mensagemDeModificadores(string caracteristica, int valorDados);
};


#endif
