#ifndef PROJETO_R_UTIL_H
#define PROJETO_R_UTIL_H

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

class Util {
private:
    bool randonized = false;
    int DADOS;
public:
    void setDados(int dados);

public:
    int recupararValorDados();

    void rolarDeDados();
    void rolarDeDados(int modificador);

    void slow_print(const string &message);
    void slow_print(const string &message, unsigned int millis_per_char);

    static void aguardarEnter();

    int aleatorioEntre(int min, int max);

    string inputString();

    static char inputChar();

    static void esperePorMilissegundos(unsigned int millis);

    void limparTela();

    static void dividirTexto(string texto, char delimitador, vector<string> &vetor);

    static void limparTelaEstatico();

    static int aleatorioEntreEstatico(int min, int max);

    static wstring utf8_to_utf16(const string &utf8);

    static string to_string(int a_value, const int n);

    static void aguardarEnterEstatico();
};


#endif //PROJETO_R_UTIL_H
