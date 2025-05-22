#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>

// Esto es para acumular puntos, no sé que nombre ponerle
class Sistema {

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
};

int main(){

};