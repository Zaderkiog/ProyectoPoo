#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

class Persona {
    private:
     string nombre;
     int identi;
     string direccion;
    public:
    Persona(string _nombre, int _identi, string _direccion): nombre(_nombre), identi(_identi), direccion(_direccion){}
};

class Usuario: public Persona{
    private:
    int puntos;
    public:
    Usuario(string _nombre, int _identi, string _direccion, int _puntos): Persona(_nombre, _identi, _direccion){}
};

// Esto es para acumular puntos, no sé que nombre ponerle
class Sistema {
  private:
    vector<Usuario*> u;
  public:
  Sistema(string _nombre, int _identi, string _direccion, Usuario _u): Usuario(_nombre, _identi, _direccion){}
  
  getFactura(){}
  
  setReporte(){}

  sorteo(){}
};

class Fruta {

};

class Carne {
  protected:
     double libra;
     int unidad;
  public:
};

class Pollo: public Carne{
  private:
    string lugarSacrificio;
};

class Cerdo: public Carne{
 private:
    string lugarSacrificio;
};

class Pescado: public Carne{
 private:
    string lugarProcedencia;
};


class Verduras {

};

class ArtIndividuales {

};

class Productor{
  private:
  vector<Pollo*> pollo;
  vector<Cerdo*> cerdo;
  vector<Pescado*> pescado;
  public:
  Productor(){}

  setProductos(){}
  
};

int main(){

};