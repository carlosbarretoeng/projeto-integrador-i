#include "Tutorial.h"

Tutorial::Tutorial(Util &pUtil, FichaDoPersonagem &pPersonagem, GeradorDeTelas &pGeradorDeTelas) {
    util = pUtil;
    fichaDoPersonagem = pPersonagem;
    geradorDeTelas = pGeradorDeTelas;
}

void Tutorial::iniciar() {
    exibirJardim();
}

void Tutorial::exibirJardim() {
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo,
                                            "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,
                                            1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
            "Bem vindo ao seu magnifico jardim.",
            "Nele voce visualiza alguns canteiros, repletos das mais variadas flores, um banquinho aconchegante para "
            "descansar, uma pequena fonte de agua em formato de peixe, jorrando agua para o ar. Ao lado, o jardineiro "
            "cuidando das delicadas rosas, apreciando seus perfumes e, mais a diante, vindo na sua direcao, "
            "o mensageiro do Rei!"
    };

    int posY = 4;
    int lastY;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 2;
    }

    string acoes[] = {
            "O que deseja fazer?",
            "(1) Conversar com o Mensageiro do Rei",
            "(2) Ir para a cozinha da casa",
            "(F) Ver a Ficha do Personagem"
    };

    posY = 19;
    for (string texto: acoes) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    char acao = util.inputChar();
    if (acao == '1') {
        exibirMensagemRei();
    } else if (acao == '2') {
        exibirCozinha();
    } else {
        fichaDoPersonagem.mostrarFichaDoPersonagem();
        exibirJardim();
    }
}

void Tutorial::exibirCozinha() {
    int posY;
    int lastY;
    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo,
                                            "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,
                                            1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
            "Voce acena para o mensageiro indicando que ira atende-lo depois e se direciona para a cozinha.",
            " ",
            "Nela, voce ve uma grande bancada, onde estao alguns alimentos a serem feitos, ve um fogao a lenha bem grande com varias panelas em cima pipocando de fervura, ve tambem panelas e copos limpos pendurados ansiando para serem usados, e por ultimo as cozinheiras e sua mae, preparando alguns pratos para o almoco."
    };

    posY = 4;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
    util.limparTela();

    string descricaoMae = "Voce repara que sua mae e uma mulher fina e de beleza rara. De pele morena e olhos escuros. "
                          "De aparencia jovem mas ao mesmo tempo transparece muita experiencia de vida. E verdadeiramente uma guerreira. "
                          "Voce nutri uma profunda admiracao por ela.";

    conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, descricaoMae, posY += 1, lastY);

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();

    util.limparTela();

    string acoes[] = {
            "O que decide fazer?",
            "(1) Conversar com o sua mae",
            "(2) Voltar para o Jardim",
            "(F) Ver a Ficha do Personagem"
    };

    posY = 19;
    for (string texto: acoes) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 23);
    conteudo = geradorDeTelas.removerUltimaLinha(conteudo);
    cout << conteudo;
    char acao = util.inputChar();
    if (acao == '1') {
        exibirMensagemMae();
    } else if (acao == '2') {
        exibirJardim();
    } else {
        fichaDoPersonagem.mostrarFichaDoPersonagem();
        exibirCozinha();
    }
}

void Tutorial::exibirMensagemRei() {
    int posY;
    int lastY;

    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo,
                                            "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,
                                            1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
            "Ele se aproxima!",
            "- Boa tarde sir " + fichaDoPersonagem.getNome() +
            "! Venho do castelo do Rei trazer-lhe esta mensagem de extrema importancia de Vossa Majestade."
    };

    posY = 4;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
    util.limparTela();

    string mensagem[] = {
            "+-------------------------------------------------------------------+",
            "| Saudacoes pequeno nobre!                                          |",
            "|                                                                   |",
            "| Venho nesta mensagem convoca-lo para o lendario Torneio Argenteo. |",
            "| Prepare sua melhor armadura, afie sua melhor espada e coma o mais |",
            "| robusto javali, em alguns dias voce trara honra para nosso reino  |",
            "| ou morrera tentando!                                              |",
            "|                                                                   |",
            "|                                             Sua Majestade, o Rei  |",
            "+-------------------------------------------------------------------+"
    };

    posY = lastY + 2;
    for (string texto: mensagem) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
    util.limparTela();

    string jardineiro[] = {
            "O jardineiro que estava ali perto se aproxima e diz para voce:",
            "- Se me permite, recomendaria que vossa senhoria busque um treinamento adequando ou ira trazer desonra para sua familia e reino!"
    };

    posY = lastY + 2;
    for (string texto: jardineiro) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 1;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}

void Tutorial::exibirMensagemMae() {
    // Voce se aproxima e chama sua mãe. Ela sorri para voce. Logo em seguida poe as mãos em seus ombros e lhe explica que, a vitoria no Torneio Argenteo é extremamente importante para o futuro da familia. O sustento e a honra da familia dependem exclusivamente dele. Seria correto tal fardo para um mero garoto?
    int posY;
    int lastY;

    util.limparTela();
    string conteudo = geradorDeTelas.gerarFrame();
    conteudo = geradorDeTelas.escreverTexto(conteudo,
                                            "UNIFAGOC - CIENCIA DA COMPUTACAO - PROJETO INTEGRADOR I - PROJETO RPG", 4,
                                            1);
    conteudo = geradorDeTelas.gerarLinhaHorizontal(conteudo, 2);

    string textos[] = {
            "Voce se aproxima e chama por sua mae. Ela sorri para voce. Logo em seguida poe as maos em seus ombros e lhe explica que, a vitoria no Torneio Argenteo e extremamente importante para o futuro da familia. O sustento ,e a honra da familia dependem exclusivamente dele. Seria correto tal fardo para um mero garoto?",
            "Logo em seguida ela o orienta a ir para o treinamento pois ve que ainda esta muito fraco e precisa desenvolver suas habilidades."
    };

    posY = 4;
    for (string texto: textos) {
        conteudo = geradorDeTelas.escreverBlocoDeTexto(conteudo, texto, posY, lastY);
        posY = lastY + 2;
    }

    conteudo = geradorDeTelas.escreverTexto(conteudo, "Pressione <ENTER>", geradorDeTelas.getWidth() - 18,
                                            geradorDeTelas.getHeight() - 2);
    cout << conteudo;
    util.aguardarEnter();
}