#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "data/persona.h"
#include "data/usuario.h"
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
   Sistema(Usuario* _cliente)  : cliente(_cliente), totalSinIVA(0), totalIVA(0), totalFinal(0) {}

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
     cliente->setPuntos(puntosActuales + puntos);
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

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

/*void display(int x, int y, int digito) {

    const char* digitos[10][5] = {
        {" **** ", "*    *", "*    *", "*    *", " **** "}, // 0
        {"  *   ", " **   ", "  *   ", "  *   ", " ***  "}, // 1
        {" **** ", "    * ", "   *  ", "  *   ", " *****"}, // 2
        {" **** ", "    * ", "  *** ", "    * ", " **** "}, // 3
        {"*   * ", "*   * ", " *****", "    * ", "    * "}, // 4
        {"***** ", "*     ", "****  ", "    * ", "****  "}, // 5
        {"  ****", " *    ", "****  ", "*    *", " **** "}, // 6
        {"***** ", "    * ", "   *  ", "  *   ", " *    "}, // 7
        {" **** ", "*    *", " **** ", "*    *", " **** "}, // 8
        {" **** ", "*    *", " *****", "    * ", " **** "}  // 9
    };

    setColor(9); // Cyan
    for(int i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        cout << digitos[digito][i];
    }
};*/

int main(){
 int tecla;
 int seleccionada = 0;
 int opcion;
 
    const int numOpciones = 10;
    string opciones[numOpciones] = {
        "1. Gestionar productos",
        "2. Ingreso de productos al inventario",
        "3. Carga masiva de productos desde archivo",
        "4. Crear factura",
        "5. Buscar producto por código y vender",
        "6. Crear reporte de inventario en archivo",
        "7. Visualizar usuarios y puntos",
        "8. Realizar sorteo con clientes por puntos",
        "9. Acciones restringidas por clave",
        "10. Ver total vendido y ganancias netas"
    };

    while (true) {
        system("cls");
        setColor(11);
        cout << "==== MENU PRINCIPAL ====" << endl;

        for (int i = 0; i < numOpciones; ++i) {
            gotoxy(3, 3 + i);
            if (i == seleccionada) {
                setColor(1); 
                cout << "> " << opciones[i] << endl;
            } else {
                setColor(10); 
                cout << "  " << opciones[i] << endl;
            }
        }

        gotoxy(3, 3 + numOpciones);
        setColor(12);
        cout << "0. Salir" << endl;

        tecla = getch();

        // Flecha arriba
        if (tecla == 72) {
            seleccionada--;
            if (seleccionada < 0) seleccionada = numOpciones - 1;
        }
        // Flecha abajo
        else if (tecla == 80) {
            seleccionada++;
            if (seleccionada >= numOpciones) seleccionada = 0;
        }
        // Enter
        else if (tecla == 13) {
            system("cls");
            cout << "Seleccionaste: " << opciones[seleccionada] << endl;
            cout << "Presiona cualquier tecla para volver al menú..." << endl;
            getch();
        }
        // Tecla '0' para salir
        else if (tecla == '0') {
            break;
        }
    }

    return 0;
}
