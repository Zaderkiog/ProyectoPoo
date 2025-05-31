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

    void setPuntos(int p){
        p = puntos;
    }
};

// Esto es para acumular puntos, no sé que nombre ponerle
class Sistema {
  private:
    vector<Usuario*> u;
  public:
  Sistema(){}
  
  void getFactura(){}
  
  void setReporte(){}

  void setAcumularpuntos(Usuario* u, int puntos){
    u->setPuntos(puntos);
  }
  
  void sorteo(){}
};

class Producto {
  private:
  string nombre;
  string tipo;
  bool porPeso;
  bool noIva;
  double precioUnitario;
  double cantidadVendida;

  public:
  Producto(string _nombre, string _tipo, bool _porPeso, bool _noIva, double _precioUnitario, double _cantidadVendida): nombre(_nombre), 
  tipo(_tipo), porPeso(_porPeso), noIva(_noIva), precioUnitario(_precioUnitario), cantidadVendida(_cantidadVendida){}

  virtual double calcularPrecio() const {
    return precioUnitario * cantidadVendida;
  }

  virtual double calcularIva() const {
    return noIva ? 0 : calcularPrecio() * 0.8;
  }
}



class Productor{
  private:

  public:
  Productor(){}

  void setProductos(){}
  
};

int main(){

};