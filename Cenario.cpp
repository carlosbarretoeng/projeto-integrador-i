#include "Cenario.h"

Cenario::Cenario(int codigo, Util &pUtil, FichaDoPersonagem &pFichaDoPersonagem, GeradorDeTelas &pGeradorDeTelas) {
    CODIGO = codigo;
    util = pUtil;
    fichaDoPersonagem = pFichaDoPersonagem;
    geradorDeTelas = pGeradorDeTelas;
}

Cenario::Cenario(RaciocinioLogicoMatematico &pDesafio, Util &pUtil, FichaDoPersonagem &pFichaDoPersonagem, GeradorDeTelas &pGeradorDeTelas) {
    CODIGO = 4;
    util = pUtil;
    fichaDoPersonagem = pFichaDoPersonagem;
    geradorDeTelas = pGeradorDeTelas;
    desafio = pDesafio;
}

void Cenario::treinar() {
    switch (CODIGO) {
        case 1:
            rodarCenario1();
            break;
        case 2:
            rodarCenario2();
            break;
        case 3:
            rodarCenario3();
            break;
        default:
            rodarCenario4();
    }
}

void Cenario::rodarCenario1() {
    cout << "CENARIO 1" << endl;
}

void Cenario::rodarCenario2() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
        "Nao muito distante de sua ultima posicao, ao caminhar pelas estradas do reino, voce se depara com um pequeno vilarejo.",
        "La voce visualiza diversas construcoes, desde a grande igreja ate uma humilde cabana familiar. Voce ve pessoas indo e vindo, comprando e vendendo, conversando e correndo, animais passando e vandalos roubando, tambem!",
        "E um vilarejo movimentado e voce ve uma chance de adquerir habilidades para enfrentar seus proximos desafios."
    };

    int posY = 4;
    int lastY;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 2;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18, geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
    util.limparTela();

    string acoes[] = {
            "O que deseja fazer?",
            "(1) Escutar historias dos ancioes da vila",
            "(2) Ir a taverna",
            "(3) Prender os vandalos",
            "(4) Atravessar a cidade sem ser visto",
            "(F) Ver a Ficha do Personagem"
    };

    posY = 17;
    for (string texto: acoes) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    char acao = util.inputChar();
    if (acao == '1'){
        util.limparTela();
        string conteudo = geradorDeTelas.gerarFrame();
        conteudo = geradorDeTelas.escreverTexto(conteudo, "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4, 1);
        conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

        string textos[] = {
                "Voce senta com os ancioes e escuta o que eles tem a dizer.",
                "-A muitos anos atras existiam varios reinos distintos. Um do leste, outro do oeste, norte e sul. "
                "Muitas guerras eram travadas na intencao de anexar pedacos de terra e expandir os reinos. Muitos guerreiros morreram. "
                "Foi um verdadeiro banho de sangue. O atrito entre os reinos crescia constantemente mas existia um que nao era de "
                "acordo com isso tudo. O nosso reino! Nosso antigo Rei, que descanse em paz, nao compactuava com essas guerras desnecessarias. "
                "Ele era um visionario. Queria que os reinos se unissem, mas eram agressivos demais para realizar uma uniao pacifica. "
                "Entao nosso Rei desenvolveu essa ideia do Torneio Argenteo, onde o vencedor controla todas as terras e tras paz aos reinos, "
                "pelo menos momentaneamente.",
        };

        int posY = 4;
        int lastY;
        for (string texto: textos) {
            conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
            posY = lastY + 2;
        }

        conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18, geradorDeTelas.getHeight() - 2);

        cout << conteudo;
        util.aguardarEnter();
        util.limparTela();

        posY = lastY + 2;
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, "Apos houvir as historias dos mais antigos, voce se sente mais sabio e preparado par os desafios. Role os dados para saber o quanto realmente aprendeu!", posY, lastY);

        conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER> para rolar os dados", geradorDeTelas.getWidth() - 38, geradorDeTelas.getHeight() - 2);
        cout << conteudo;
        util.aguardarEnter();

        util.limparTela();
        conteudo = geradorDeTelas.gerarFrame();

        util.rolarDeDados(3);
        geradorDeTelas.rolarDeDados(util.recupararValorDados(), conteudo);

        fichaDoPersonagem.modificarCaracteristica("SABEDORIA", util.recupararValorDados());

        string mensagem = "Apos ouvir a longa historia dos ancioes, voce fica pensativo, refletindo se tudo isso era "
            "realmente necessario. Existem tantas solucoes para este conflito. Sera que os reinos gostam de lutas "
            "baratas e mortes? E usam este torneio como desculpa para tal? Humm... Interessante...";

        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, mensagem, posY, lastY);

        cout << conteudo;
        util.aguardarEnter();
    }
}

void Cenario::rodarCenario3() {
    cout << "CENARIO 3" << endl;
}

void Cenario::rodarCenario4() {
    cout << "CENARIO 4" << endl;
}
