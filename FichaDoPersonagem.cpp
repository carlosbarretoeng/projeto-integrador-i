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
    Util::limparTelaEstatico();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo,
                                            "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,
                                            1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
            "STATUS DO PERSONAGEM:",
            "",
            "     NOME: " + getNome(),
            "     VIDA: " + Util::to_string(getVida(), 2),
            "SABEDORIA: " + Util::to_string(getSabedoria(), 2),
            "    FORCA: " + Util::to_string(getForca(), 2),
    };

    int lastY = 2;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, ++lastY, lastY);
    }

    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, lastY);

    string modificadores[] = {
            "MODIFICADORES:",
            "",
            "POSITIVA-VITAL: Garante um acressimo de 2 pontos no atributo afetado e "
            "                     adiciona 0.25 pontos de vida.",
            "      POSITIVA: Garante um acressimo de 1 pontos no atributo afetado.",
            "        NEUTRA: Nao altera os status do personagem.",
            "      NEGATIVA: Reduz em 1 ponto o atributo afetado. Nao aplicado se "
            "                       atributo for menor que 1.",
            "NEGATIVA-VITAL: Reduz em 2 ponto o atributo afetado e em 0.75 pontos a "
            "                     vida. Nao aplicado se atributo for menor que 2, mas ainda "
            "                  assim altera a vida.",
    };

    for (string texto: modificadores) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, ++lastY, lastY);
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18, geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    Util::aguardarEnterEstatico();
}

bool FichaDoPersonagem::modificador(string caracteristica, int valor) {
    switch (valor) {
        case 6:
            aplicarModificador("VIDA", 0.25f);
            aplicarModificador(caracteristica, 2.0f);
            return true;
        case 5:
            aplicarModificador(caracteristica, 1.0f);
            return true;
        case 2:
            if(caracteristica == "SABEDORIA" && getSabedoria() < 2) return false;
            if(caracteristica == "FORÇA" && getForca() < 2) return false;
            aplicarModificador(caracteristica, -1.0f);
            return true;
        case 1:
            aplicarModificador("VIDA", -0.75f);
            if(caracteristica == "SABEDORIA" && getSabedoria() < 3) return false;
            if(caracteristica == "SABEDORIA" && getSabedoria() < 3) return false;
            aplicarModificador(caracteristica, -2.0f);
            return true;
        default:
            return true;
    }
}

void FichaDoPersonagem::aplicarModificador(string caracteristica, float valor){
    if(caracteristica == "VIDA") setVida(getVida() + valor);
    if(caracteristica == "SABEDORIA") setSabedoria(getSabedoria() + valor);
    if(caracteristica == "FORCA") setForca(getForca() + valor);
}

void FichaDoPersonagem::setGeradorDeTelas(const GeradorDeTelas &geradorDeTelas) {
    FichaDoPersonagem::geradorDeTelas = geradorDeTelas;
}

string FichaDoPersonagem::mensagemDeModificadores(string caracteristica, int valorDados) {
    switch (valorDados) {
        case 6:
            return "SUCESSO! Voce obteve um acerto critico e recebeu 2 pontos de " + caracteristica + " e mais 0.25 de VIDA";
        case 5:
            return "Legal! Voce obteve um bom resultado e recebeu 1 pontos de " + caracteristica;
        case 2:
            return "Cuidado! Voce obteve um aml resultado e perdeu 1 pontos de " + caracteristica;
        case 1:
            return "Cuidado! Voce obteve um aml resultado e perdeu 1 pontos de " + caracteristica;
        default:
            return "Nao foi dessa vez, mas continue tentando! (Sua vida depende disso!)";
    }
}
