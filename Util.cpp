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
        if (input.length() != 1 &&
            !(input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4' || input[0] == 'F' ||
              input[0] == 'f' || input[0] == 'V' || input[0] == 'v')) {
            cout << "Entrada inválida! Por favor, use apenas uma das opcoes" << endl;
            cout << "|: ";
        }
    } while (input.length() != 1);
    return toupper(input[0]);
}

void Util::aguardarEnter() {
    while (cin.get() != '\n');
}

void Util::aguardarEnterEstatico() {
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

std::wstring Util::utf8_to_utf16(const std::string &utf8) {
    std::vector<unsigned long> unicode;
    size_t i = 0;
    while (i < utf8.size()) {
        unsigned long uni;
        size_t todo;
        bool error = false;
        unsigned char ch = utf8[i++];
        if (ch <= 0x7F) {
            uni = ch;
            todo = 0;
        } else if (ch <= 0xBF) {
            throw std::logic_error("not a UTF-8 string");
        } else if (ch <= 0xDF) {
            uni = ch & 0x1F;
            todo = 1;
        } else if (ch <= 0xEF) {
            uni = ch & 0x0F;
            todo = 2;
        } else if (ch <= 0xF7) {
            uni = ch & 0x07;
            todo = 3;
        } else {
            throw std::logic_error("not a UTF-8 string");
        }
        for (size_t j = 0; j < todo; ++j) {
            if (i == utf8.size())
                throw std::logic_error("not a UTF-8 string");
            unsigned char ch = utf8[i++];
            if (ch < 0x80 || ch > 0xBF)
                throw std::logic_error("not a UTF-8 string");
            uni <<= 6;
            uni += ch & 0x3F;
        }
        if (uni >= 0xD800 && uni <= 0xDFFF)
            throw std::logic_error("not a UTF-8 string");
        if (uni > 0x10FFFF)
            throw std::logic_error("not a UTF-8 string");
        unicode.push_back(uni);
    }
    std::wstring utf16;
    for (size_t i = 0; i < unicode.size(); ++i) {
        unsigned long uni = unicode[i];
        if (uni <= 0xFFFF) {
            utf16 += (wchar_t) uni;
        } else {
            uni -= 0x10000;
            utf16 += (wchar_t) ((uni >> 10) + 0xD800);
            utf16 += (wchar_t) ((uni & 0x3FF) + 0xDC00);
        }
    }
    return utf16;
}

string Util::to_string(int a_value, const int n = 6) {
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}