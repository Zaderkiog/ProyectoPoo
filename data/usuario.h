#ifndef USUARIO_H
#define USUARIO_H
#include "persona.h"
#include <string>
using namespace std;

class Usuario : public Persona {
private:
    int puntos;
public:
    Usuario(string _nombre, int _identi, string _direccion, int _puntos): Persona(_nombre, _identi, _direccion){}
    void setPuntos(int p);
    int getPuntos();
};
#endif