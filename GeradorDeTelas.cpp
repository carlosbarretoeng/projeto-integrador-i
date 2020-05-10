#include "GeradorDeTelas.h"

GeradorDeTelas::GeradorDeTelas() {
}

string GeradorDeTelas::gerarFrame() {
    stringstream buffer;
    for(int i=0; i<getHeight(); i++){
        for(int j=0; j<getWidth(); j++){
            if(i == 0){
                if(j == 0) buffer << "+";
                else if(j == (getWidth() - 1))  buffer << "+";
                else buffer << "-";
            }else if( i == (getHeight() - 1)){
                if(j == 0) buffer << "+";
                else if(j == (getWidth() - 1))  buffer << "+";
                else buffer << "-";
            }else{
                if(j == 0 || j == (getWidth() - 1)) buffer << "|";
                else buffer << " ";
            }
        }
        if(i != (getHeight() - 1)) buffer << "\n";
    }

    string out = escreverVersao(buffer.str());

    return out;
}

string GeradorDeTelas::escreverVersao(string frame) {
    string versao = " v0.1 beta ";
    frame.replace(getWidth() - 13, versao.length(), versao);
    return frame;
}

string GeradorDeTelas::escreverLogo(string frame, int posX, int posY) {
    string logo[] = {
            " ######                                              ######  ",
            " #     # #####   ####       # ###### #####  ####     #     # ",
            " #     # #    # #    #      # #        #   #    #    #     # ",
            " ######  #    # #    #      # #####    #   #    #    ######  ",
            " #       #####  #    #      # #        #   #    #    #   #   ",
            " #       #   #  #    # #    # #        #   #    #    #    #  ",
            " #       #    #  ####   ####  ######   #    ####     #     # "
    };
    for(int i=0; i<7; i++){
        frame = escreverTexto(frame, logo[i], posX, posY + i);
    }
    return frame;
}

string GeradorDeTelas::escreverTexto(string frame, string texto, int posX, int posY) {
    int posicao = posY * getWidth() + posX + posY;
    int len = texto.length();
    frame.replace(posicao, len, texto);
    return frame;
}

string GeradorDeTelas::escreverBlocoDeTexto(string frame, string texto, int posY, int &last) {
    int posX = 3;
    int limiteLinha = getWidth() - 4;
    vector<string> palavras;
    Util::dividirTexto(texto, ' ', palavras);

    string linha = "";
    for(string palavra: palavras){
        if((palavra.length() + linha.length() + 1) <= limiteLinha && palavra != "\n"){
            linha += palavra + " ";
        }else{
            frame = escreverTexto(frame, linha, posX, posY);
            linha = palavra != "\n" ? (palavra + " ") : "";
            posY++;
        }
    }
    last = posY;
    frame = escreverTexto(frame, linha, posX, posY);
    return frame;
}


string GeradorDeTelas::escreverBlocoDeTexto(string frame, string texto, int posY) {
    int pnull;
    return escreverBlocoDeTexto(frame,texto,posY, pnull);
}

string GeradorDeTelas::gerarLinhaHorizontal(string frame, int posY){
    stringstream buffer;
    if(posY == 0 || posY == getHeight() - 1) return frame;
    for(int j=0; j<getWidth(); j++){
        if(j == 0 || j == (getWidth() - 1)) buffer << "+";
        else buffer << "-";
    }
    return escreverTexto(frame, buffer.str(), 0, posY);
}

string GeradorDeTelas::removerUltimaLinha(string frame){
    stringstream buffer;
    for(int i=0; i<(frame.size() - getWidth()); i++) buffer << frame[i];
    return buffer.str();
}

void GeradorDeTelas::rolarDeDados(){
    for(int i=0; i<10; i++){
        Util::limparTelaEstatico();
        string conteudo = gerarFrame();
        conteudo = escreverTexto(conteudo,"UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,1);
        conteudo = gerarLinhaHorizontal(conteudo, 2);

        int pos = 0;
        for(string l: dados[Util::aleatorioEntreEstatico(0,5)]){
            conteudo = escreverTexto(conteudo, l, 35, 9 + pos);
            pos++;
        }

        cout << conteudo;

        Util::esperePorMilissegundos(500);
    }
}

void GeradorDeTelas::rolarDeDados(int valor, string &conteudo){
    rolarDeDados();

    Util::limparTelaEstatico();
    conteudo = gerarFrame();
    conteudo = escreverTexto(conteudo,"UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,1);
    conteudo = gerarLinhaHorizontal(conteudo, 2);

    int pos = 0;
    for(string l: dados[valor]){
        conteudo = escreverTexto(conteudo, l, 35, 9 + pos);
        pos++;
    }

    cout << conteudo;
}

void GeradorDeTelas::setWidth(int width) {
    WIDTH = width;
}

void GeradorDeTelas::setHeight(int height) {
    HEIGHT = height;
}

int GeradorDeTelas::getWidth() const {
    return WIDTH;
}

int GeradorDeTelas::getHeight() const {
    return HEIGHT;
}
