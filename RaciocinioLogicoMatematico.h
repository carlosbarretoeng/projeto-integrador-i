#ifndef PROJETO_R_RACIOCINIOLOGICOMATEMATICO_H
#define PROJETO_R_RACIOCINIOLOGICOMATEMATICO_H

#include <ostream>
#include "Util.h"

class RaciocinioLogicoMatematico {
private:
    bool FEITO = false;
    string ENUNCIADO;
    string RESPOSTA;

public:
    void print();

    bool estaFeito();
};


#endif //PROJETO_R_RACIOCINIOLOGICOMATEMATICO_H
