#ifdef PERSONA_H
#define PERSONA_H

class Persona {
    private:
     string nombre;
     int identi;
     string direccion;
    public:
    Persona(string _nombre, int _identi, string _direccion): nombre(_nombre), identi(_identi), direccion(_direccion){}
};

#endif