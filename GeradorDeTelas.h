#ifndef PROJETO_R_GERADORDETELAS_H
#define PROJETO_R_GERADORDETELAS_H

#include "Util.h"

class GeradorDeTelas {
private:
    int WIDTH;
    int HEIGHT;

    string dados[6][7] = {
            {
                    "+-----+",
                    "|     |",
                    "|  #  |",
                    "|     |",
                    "+-----+",
            },
            {
                    "+-----+",
                    "|   # |",
                    "|     |",
                    "| #   |",
                    "+-----+",
            },
            {
                    "+-----+",
                    "|   # |",
                    "|  #  |",
                    "| #   |",
                    "+-----+",
            },
            {
                    "+-----+",
                    "| # # |",
                    "|     |",
                    "| # # |",
                    "+-----+",
            },
            {
                    "+-----+",
                    "| # # |",
                    "|  #  |",
                    "| # # |",
                    "+-----+",
            },
            {
                    "+-----+",
                    "| # # |",
                    "| # # |",
                    "| # # |",
                    "+-----+",
            }
    };

public:
    GeradorDeTelas();

    void setWidth(int width);
    void setHeight(int height);

    int getWidth() const;

    int getHeight() const;

    string gerarFrame();

    string escreverVersao(string frame);

    string escreverLogo(string frame, int posX, int posY);

    string escreverTexto(string frame, string texto, int posX, int posY);

    string gerarLinhaHorizontal(string frame, int posY);

    string removerUltimaLinha(string frame);

    string escreverBlocoDeTexto(string frame, string texto, int posY);
    string escreverBlocoDeTexto(string frame, string texto, int posY, int &last);

    void rolarDeDados(int valor, string &conteudo);

    void rolarDeDados();
};


#endif //PROJETO_R_GERADORDETELAS_H
