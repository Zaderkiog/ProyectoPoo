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
};

class Usuario: public Persona{
    private:
    int puntos;
};

// Esto es para acumular puntos, no sé que nombre ponerle
class Sistema {
  private:
    vector<Usuario*> u;
  
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