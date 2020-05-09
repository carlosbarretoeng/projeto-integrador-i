#ifndef PROJETO_R_CENARIO_H
#define PROJETO_R_CENARIO_H

#include "Util.h"
#include "RaciocinioLogicoMatematico.h"
#include "FichaDoPersonagem.h"
#include "GeradorDeTelas.h"

class Cenario{
private:
    Util util;
    GeradorDeTelas geradorDeTelas;
    FichaDoPersonagem fichaDoPersonagem;
    RaciocinioLogicoMatematico desafio;

    int CODIGO;

public:
    Cenario(int codigo, Util &pUtil, FichaDoPersonagem &fichaDoPersonagem, GeradorDeTelas &pGeradorDeTelas);
    Cenario(RaciocinioLogicoMatematico &desafio, Util &pUtil, FichaDoPersonagem &fichaDoPersonagem, GeradorDeTelas &pGeradorDeTelas);

    void treinar();

    void rodarCenario1();

    void rodarCenario2();

    void rodarCenario3();

    void rodarCenario4();
};


#endif //PROJETO_R_CENARIO_H
