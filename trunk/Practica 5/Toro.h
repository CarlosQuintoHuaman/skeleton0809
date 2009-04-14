//---------------------------------------------------------------------------

#ifndef ToroH
#define ToroH
#include "Malla.h"

//---------------------------------------------------------------------------

class Toro : public Malla {

  private:
      GLint nP; // n� lados pol�gono
      GLint nQ; // n� capas
      GLfloat  radio1, radio2;

  public:
      Toro(int numLados, int particiones, GLfloat r1, GLfloat r2);
      ~Toro();
      void Frenet(PV3D** poligono, int lados);
      //void moverPoligono(PV3D** poligono, int lados, PV3D* centro, GLfloat grados, int indice);
};

//---------------------------------------------------------------------------

#endif
