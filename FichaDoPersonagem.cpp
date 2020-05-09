#include "FichaDoPersonagem.h"

FichaDoPersonagem::FichaDoPersonagem() {
    NOME = "";
    VIDA = 100;
    SABEDORIA = 10;
    FORCA = 10;
}

FichaDoPersonagem::FichaDoPersonagem(const string &nome) : NOME(nome) {
    NOME = nome;
    VIDA = 100;
    SABEDORIA = 10;
    FORCA = 10;
}

const string &FichaDoPersonagem::getNome() const {
    return NOME;
}

void FichaDoPersonagem::setNome(const string &nome) {
    NOME = nome;
}

float FichaDoPersonagem::getVida() const {
    return VIDA;
}

void FichaDoPersonagem::setVida(float vida) {
    VIDA = vida;
}

float FichaDoPersonagem::getForca() const {
    return FORCA;
}

void FichaDoPersonagem::setForca(float forca) {
    FORCA = forca;
}

float FichaDoPersonagem::getSabedoria() const {
    return SABEDORIA;
}

void FichaDoPersonagem::setSabedoria(float sabedoria) {
    SABEDORIA = sabedoria;
}

void FichaDoPersonagem::mostrarFichaDoPersonagem() {
    cout << NOME << "\t" << VIDA << "\t" << SABEDORIA << "\t" << FORCA << endl;
    cout << "MODIFICADORES" << endl;
}

bool FichaDoPersonagem::modificarCaracteristica(string caracteristica, int valor) {
    bool retorno = false;
    switch (valor) {
        case 6:
            retorno = aplicaPositivaVital(caracteristica);
            break;
        case 5:
            retorno = aplicaPositiva(caracteristica);
            break;
        case 2:
            retorno = aplicaNegativa(caracteristica);
            break;
        case 1:
            retorno = aplicaNegativaVital(caracteristica);
            break;
        default:
            break;
    }
    return false;
}

bool FichaDoPersonagem::aplicaPositivaVital(string caracteristica) {

}

bool FichaDoPersonagem::aplicaPositiva(string caracteristica) {

}

bool FichaDoPersonagem::aplicaNegativa(string caracteristica) {

}

bool FichaDoPersonagem::aplicaNegativaVital(string caracteristica) {

}
