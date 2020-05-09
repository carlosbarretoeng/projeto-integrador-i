#include "Util.h"

void Util::rolarDeDados() {
    Util::rolarDeDados(0);
}

void Util::rolarDeDados(int modificador) {
    setDados(aleatorioEntre((1 + modificador), 6));
}

int Util::recupararValorDados() {
    return DADOS;
}

void Util::setDados(int dados) {
    DADOS = dados;
}

string Util::inputString() {
    cout << ": ";
    string input;
    getline(cin, input);
    return input;
}

char Util::inputChar() {
    cout << flush << "|: ";
    string input;
    do {
        getline(cin, input);
        if (input.length() != 1) {
            cout << "Entrada inválida! Por favor, use apenas um caracter" << endl;
            cout << "|: ";
        }
    } while (input.length() != 1);
    return input[0];
}

void Util::aguardarEnter() {
    while (cin.get() != '\n');
}

void Util::slow_print(const string &message) {
    slow_print(message, 30);
}

void Util::slow_print(const string &message, unsigned int millis_per_char) {
    for (const char c: message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(millis_per_char));
    }
}

void Util::esperePorMilissegundos(unsigned int millis) {
    bool block = true;
    while (block) {
        block = false;
        this_thread::sleep_for(chrono::milliseconds(millis));
    }
}

int Util::aleatorioEntreEstatico(int min, int max) {
    return (min + (rand() % (max + 1 - min)));
}

int Util::aleatorioEntre(int min, int max) {
    if (!randonized) {
        srand(time(NULL));
        randonized = true;
    }
    return (min + (rand() % (max + 1 - min)));
}

void Util::limparTela() {
    system("clear");
}

void Util::limparTelaEstatico() {
    system("clear");
}

void Util::dividirTexto(string texto, char delimitador, vector<string> &vetor) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(texto);
    while (std::getline(tokenStream, token, delimitador)) {
        tokens.push_back(token);
    }
    vetor = tokens;
}
