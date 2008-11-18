//---------------------------------------------------------------------------

 #ifndef LapizH
 #define LapizH
 #include "Punto.h"       //Para el tipo Punto
 #include <math.h>      //Librer�a funciones matem�ticas
 #include <gl\gl.h>     //Librer�a OPENGL
 #include <gl\glu.h>

 class Lapiz
 {
        private:
                Punto* posicion;     //Punto donde se encuentra el lapiz
                float direccion;        //Direcci�n (�ngulo en grados): 0� a 359�
        public:
                Lapiz();    //Constructores
                Lapiz(Punto* pos);
                Lapiz(Punto* pos, float dir);
                ~Lapiz();   //Destructor
                //Accesores y mutadores
                Punto* getPosicion();
                void lineTo(Punto* punto);
                void moveTo(Punto* punto);
                void moveToRel(float incrX, float incrY);
                void turn(float dir);
                void turnTo(float dir);
                void avanzar(float distancia, bool traza);
 };

//---------------------------------------------------------------------------

 #endif
