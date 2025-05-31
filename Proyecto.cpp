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
    Usuario(string _nombre, int _identi, string _direccion, int _puntos): Persona(_nombre, _identi, _direccion), puntos(_puntos){}

    void setPuntos(int p){
        puntos = p;
    }

    int getPuntos(){ return puntos; }
};


class Producto {
  protected:
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
    return noIva ? 0 : calcularPrecio() * 0.19;
  }

  void setCantidadVendida(double _cantidadVendida){
    this->cantidadVendida = _cantidadVendida;
  }

  virtual void mostrarDetalle() const {
        cout << nombre << " - " << cantidadVendida << (porPeso ? " lb" : " u") << " - $" << fixed << setprecision(2)
             << calcularPrecio() << " (IVA: $" << calcularIva() << ")" << endl;
    }
};

class Carne : public Producto {
  private:
  string tipoCarne;
  string lugarSacrificio;
  string procedenciaPescado;
  public:
  Carne(string _nombre, string _tipo, bool _porPeso, bool _noIva, double _precioUnitario, 
    double _cantidadVendida, string _tipoCarne, string _lugarSacrificio = "", string procedenciaPescado = ""): Producto(
      _nombre, _tipo, _porPeso, _noIva, _precioUnitario, _cantidadVendida){}

   double calcularPrecio() const override{
     double base = Producto::calcularPrecio();
     if (tipoCarne == "pescado" && procedenciaPescado == "mar"){
       base += 0.5;
     } else {
      return base;
     }
   }

   void mostrarDetalle() const override{
     Producto::mostrarDetalle();
     if (tipoCarne == "res"){
        cout << "Lugar de sacrifcio: " << lugarSacrificio << endl;
     }
     if (tipoCarne == "pescado"){
       cout << "Lugar de procedencia: " << procedenciaPescado << endl;
     }
   }
};

class Sistema {
   private:
   Usuario* cliente;
   vector<Producto*> productos;
   double totalSinIVA = 0;
   double totalIVA = 0;
   double totalFinal = 0;
   int puntos = 0;
   public:
       Sistema(Usuario* _cliente, vector<Producto*> _productos, double _totalSinIVA, double _totalIVA, double _totalFinal)
        : cliente(_cliente), productos(_productos), totalSinIVA(_totalSinIVA), totalIVA(_totalIVA), totalFinal(_totalFinal) {}

   void agregarProductos(Producto* _productos, double cantidad) {
      _productos->setCantidadVendida(cantidad);
      productos.push_back(_productos);
   }

   void CalcularFactura(){
     for (Producto* p: productos){
      totalSinIVA += p->calcularPrecio();
      totalIVA += p->calcularIva();
     }

     totalFinal = totalIVA + totalSinIVA;

     int puntosActuales = cliente->getPuntos();
     cliente->setPuntos(puntosActuales + puntos) 
   }

   void MostrarFactura(){
      cout << "==== Factura ====" << endl;
      
      for (Producto* p : productos){
        p->mostrarDetalle();
      }

      cout << "=========================" << endl;
      cout << "Subtotal: " << endl;
      cout << "Total IVA: " << endl;
      cout << "Total a pagar: " << totalFinal << setprecision(3) << endl;
      cout << "Puntos: " << puntos << endl;
      cout << "==========================" << endl;
   }

};

int main(){

};