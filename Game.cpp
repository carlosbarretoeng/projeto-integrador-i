#include "Game.h"
#include "Tutorial.h"
#include "Cenario.h"

Game::Game(int width, int height){
    Game(width, height, *(new vector<RaciocinioLogicoMatematico>), *(new GeradorDeTelas()));
    WIDTH = width;
    HEIGHT = height;
    geradorDeTelas.setWidth(WIDTH);
    geradorDeTelas.setHeight(HEIGHT);
    fichaDoPersonagem.setGeradorDeTelas(geradorDeTelas);


}

Game::Game(int width, int height, vector<RaciocinioLogicoMatematico> desafiosRlm, GeradorDeTelas gerador) : WIDTH(width), HEIGHT(height), desafiosRLM(desafiosRlm), geradorDeTelas(gerador) {
}

void Game::start() {
    // warmup();

    /*telaDeApresentacao();
    telaDeSelecaoDaDificuldade();
    telaDeIntroducaoDaHistoria();
    telaDeIntroducaoDoPersonagem();
    (new Tutorial(util,fichaDoPersonagem, geradorDeTelas))->iniciar();*/
    // telaDeConviteAExploracao();

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

    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Jogo RPG Text-Adventure para a disciplina de Projeto Integrador I desenvolvido pelos alunos Carlos Barreto, Italo Rocha, Joao Pedro Thinassi, Matheus Drumond e Gustavo Martins.", 20);

     conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeSelecaoDaDificuldade() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO R", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int pos = 4;
    int last;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Seja bem vind@!", pos, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "    Nosso objetivo é trazer de forma ludica e divertida um pouco do conteudo das disciplinas de Raciocínio Logico Matematico e Producao de Texto. Esperamos que se divirta! Vamos comecar?", ++last, last);

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
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO R", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int last;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Nossa historia comeca em tempo muito diferente do nosso. Por geracoes e mais geracoes, um pequeno feudo no limiar de dois imperios e disputado com sangue e inteligencia por duas familias reais.", 4, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "A cada 40 anos, cada familia elege dentre os seus vassalos um campeao. Este sera o responsavel por conquistar a honra ou carregar o fardo da derreto de seu reino.", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "O Torneio Argenteo e o divisor de aguas na vida dos campeoes eleitos. A vitoria garante a honra e favores que so os mais altos nobres alcancam. A derrota, desgraca a vida do vassalo e marca sua familia por mais 40 anos de trabalhos infindaveis.", ++last, last);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeIntroducaoDoPersonagem() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO R", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int last;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Dentre todos os nobres que habitavam aquele pequeno feudo, um nao fazia questao alguma de preocupar-se com aquele torneio. De fato, nem mesmo lembrava de quando seria disputado.", 4, last);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();

    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Nosso pequeno nobre ...", ++last, last);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Selecione o nome do seu Personagem:", 1, 22);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    string nome = util.inputString();
    fichaDoPersonagem.setNome(nome);

    util.limparTela();
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Nosso pequeno nobre, sir " + fichaDoPersonagem.getNome() + ", fazia mais questao de administrar os bens que seu pai deixara, a dar atencao ao treinamento que era de praxe todos os jovens de sua idade fazerem.", last--, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Mal sabia que seu destino estava prestes a mudar. Seus dias jamais voltariam a ser calmos e tranquilos. Suas responsabilidades seriam vezes aumentadas.", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++last, last);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Ate que em um dia como outro qualquer...", ++last, last);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", getWidth() - 18, getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Game::telaDeConviteAExploracao() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO R", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    int lastY;
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "A jornada se inicia.", 4, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++lastY, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Agora nosso heroi precisa sair em busca de desafios para aprimorar cada vez meis seu corpo e sua mente. Você ira caminhar pelas estradas do feudo em busca de qualquer dica de como se tornar um combatente mais rapido, forte e tatico. Ou ainda, achar uma solucao definitiva para esse torneio que por geracoes tem tirado a vida de muitos.", ++lastY, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++lastY, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "A cada novo cenario, voce sera confrontado com escolhas a fazer e caminhos a tomar. Cada um podera te levar a experiencias incriveis ou a dores tenebrosas.", ++lastY, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "", ++lastY, lastY);
    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Escolha com sabedoria e resista fortemente!", ++lastY, lastY);

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
    return (todosOsDesafiosJaForamFeitos || fichaDoPersonagem.getVida() <= 0);
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
