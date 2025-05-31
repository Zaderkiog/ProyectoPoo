#ifndef PERSONA_H
#define PERSONA_H

class Persona {
    private:
     std::string nombre;
     int identi;
     std::string direccion;
    public:
    Persona(std::string _nombre, int _identi, std::string _direccion): nombre(_nombre), identi(_identi), direccion(_direccion){}

    void getDatos();
};

#endif