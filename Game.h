#ifndef PROJETO_R_GAME_H
#define PROJETO_R_GAME_H

#include <vector>
#include "Util.h"
#include "FichaDoPersonagem.h"
#include "RaciocinioLogicoMatematico.h"
#include "GeradorDeTelas.h"

class Game {
private:
    Util util;
    FichaDoPersonagem fichaDoPersonagem;
    GeradorDeTelas geradorDeTelas;
    vector<RaciocinioLogicoMatematico> desafiosRLM;

    int WIDTH;
    int HEIGHT;
    int DIFICULDADE;
public:
    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

public:
    Game(int width, int height);
    Game(int width, int height, vector <RaciocinioLogicoMatematico> desafiosRlm, GeradorDeTelas gerador);

    void start();

    void telaDeApresentacao();
    void telaDeSelecaoDaDificuldade();
    void telaDeIntroducaoDaHistoria();
    void telaDeIntroducaoDoPersonagem();
    void telaDeApresentacaoDoDesafio();
    void telaDeConviteAExploracao();

    bool avaliarCondicaoDeParadaDeTreinamento();

    void telaDeGameOver();

    bool avaliarCondicaoDeTorneio();

    void telaDeSucesso();

    void telaDeCreditos();

    void warmup();
};


#endif //PROJETO_R_GAME_H
