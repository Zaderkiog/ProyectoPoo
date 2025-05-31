#ifdef USUARIO_H
#define USUARIO_H
#include "persona.h"

class Usuario: public Persona{
    private:
    int puntos;
    public:
    Usuario(string _nombre, int _identi, string _direccion, int _puntos): Persona(_nombre, _identi, _direccion), puntos(_puntos){}

    void setPuntos(int p);

    int getPuntos();
};
#endif