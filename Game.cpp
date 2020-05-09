#include "Game.h"
#include "Tutorial.h"
#include "Cenario.h"

Game::Game(int width, int height){
    Game(width, height, *(new vector<RaciocinioLogicoMatematico>), *(new GeradorDeTelas()));
    WIDTH = width;
    HEIGHT = height;
    geradorDeTelas.setWidth(WIDTH);
    geradorDeTelas.setHeight(HEIGHT);
}

Game::Game(int width, int height, vector<RaciocinioLogicoMatematico> desafiosRlm, GeradorDeTelas gerador) : WIDTH(width), HEIGHT(height), desafiosRLM(desafiosRlm), geradorDeTelas(gerador) {
}

void Game::start() {
    warmup();

    telaDeApresentacao();
    telaDeSelecaoDaDificuldade();
    telaDeIntroducaoDaHistoria();
    telaDeIntroducaoDoPersonagem();
    telaDeApresentacaoDoDesafio();
    (new Tutorial(util,fichaDoPersonagem, geradorDeTelas))->iniciar();
    telaDeConviteAExploracao();

    bool condicaoDeParadaDeTreinamento = false;
    int etapasDesdeUltimoDesafioRLM = 0;
    while(!condicaoDeParadaDeTreinamento){
        /*int sorteio = util.aleatorioEntre(1, 100);
        if(etapasDesdeUltimoDesafioRLM > 5 || sorteio <= 10){
            for(RaciocinioLogicoMatematico desafio: desafiosRLM){
                if(!desafio.estaFeito()){
                    (new Cenario(desafio, fichaDoPersonagem))->treinar();
                }
            }
            etapasDesdeUltimoDesafioRLM = 0;
        }else if(sorteio <= 30){
            etapasDesdeUltimoDesafioRLM++;
            (new Cenario(3, fichaDoPersonagem))->treinar();
        }else if(sorteio <= 65){
            etapasDesdeUltimoDesafioRLM++;*/
            (new Cenario(2, util, fichaDoPersonagem, geradorDeTelas))->treinar();/*
        }else{
            etapasDesdeUltimoDesafioRLM++;
            (new Cenario(1, util, fichaDoPersonagem, geradorDeTelas))->treinar();
        }*/
        condicaoDeParadaDeTreinamento = avaliarCondicaoDeParadaDeTreinamento();
    }

    util.aguardarEnter();

    if(avaliarCondicaoDeTorneio()){
        // TODO: Executar torneio
    }else{
        telaDeGameOver();
        telaDeCreditos();
        return;
    }

    if(fichaDoPersonagem.getVida() > 0){
        telaDeSucesso();
    }else{
        telaDeGameOver();
    }

    telaDeCreditos();
}

void Game::telaDeApresentacao() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "CENTRO UNIVERSITARIO GOVERNADOR OZANAN COELHO - UNIFAGOC", 11, 1);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I", 18, 2);
    conteudo = geradorDeTelas.escreverLogo(conteudo, 9, 7);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Jogo RPG Text-Adventure para a disciplina de Projeto Integrador I desenvolvido", 1, 20);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "pelos alunos Carlos Barreto, Italo Rocha, Joao Pedro Thinassi, Matheus Drumond", 1, 21);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "e Gustavo Martins.", 1, 22);

     conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeSelecaoDaDificuldade() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Selecione a dificuldade da aventura:", 1, 19);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "(1) Facil", 1, 20);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "(2) Medio", 1, 21);
    conteudo = geradorDeTelas.escreverTexto(conteudo, "(3) Dificil", 1, 22);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    DIFICULDADE = util.inputChar();
}

void Game::telaDeIntroducaoDaHistoria() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    conteudo = geradorDeTelas.escreverTexto(conteudo, " Nossa história começa em ...", 2, 4);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeIntroducaoDoPersonagem() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Selecione o nome do seu Personagem:", 1, 22);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    string nome = util.inputString();
    fichaDoPersonagem.setNome(nome);
}

void Game::telaDeApresentacaoDoDesafio() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int lastY;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "O Torneio Argenteo ...", 4, lastY);

     conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeConviteAExploracao() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int lastY;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "A jornada se inicia...", 4, lastY);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

bool Game::avaliarCondicaoDeParadaDeTreinamento() {
    bool todosOsDesafiosJaForamFeitos = true;
    for(RaciocinioLogicoMatematico desafio: desafiosRLM){
        if(!desafio.estaFeito()){
            todosOsDesafiosJaForamFeitos = false;
            break;
        }
    }
    return (todosOsDesafiosJaForamFeitos);
}

bool Game::avaliarCondicaoDeTorneio() {
    return false;
}

void Game::telaDeGameOver() {
    cout << "GAME OVER" << endl;
    util.aguardarEnter();
}

void Game::telaDeSucesso() {
    cout << "SUCESSO" << endl;
    util.aguardarEnter();
}

void Game::telaDeCreditos() {
    cout << "CREDITOS" << endl;
    util.aguardarEnter();
}

void Game::warmup() {
    cout << "Melhor visualizado em " << WIDTH << "x" << HEIGHT << "." << endl;
    cout << "Após redefinir, tecle <ENTER>." << endl;
    util.aguardarEnter();
}

int Game::getWidth() const {
    return WIDTH;
}

void Game::setWidth(int width) {
    WIDTH = width;
}

int Game::getHeight() const {
    return HEIGHT;
}

void Game::setHeight(int height) {
    HEIGHT = height;
}
