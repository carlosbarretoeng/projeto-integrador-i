#ifndef PROJETO_R_TUTORIAL_H
#define PROJETO_R_TUTORIAL_H

#include "Game.h"

class Tutorial{
private:
    Util util;
    FichaDoPersonagem fichaDoPersonagem;
    GeradorDeTelas geradorDeTelas;
public:
    Tutorial(Util &pUtil, FichaDoPersonagem &pPersonagem, GeradorDeTelas &pGeradorDeTelas);
    void iniciar();

    void exibirJardim();

    void exibirCozinha();

    void exibirMensagemRei();

    void exibirMensagemMae();
};


#endif //PROJETO_R_TUTORIAL_H
