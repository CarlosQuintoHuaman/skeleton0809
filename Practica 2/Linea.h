//---------------------------------------------------------------------------

 #ifndef LineaH
 #define LineaH
  #include "PuntoV2F.h"
 #include "DibujoLineas.h"
 #include "Lapiz.h"
  #include "Lista.h"
    #include "Linea.h"
    #include "Linea.h"
 #include <gl\gl.h>     //Librer�a OPENGL
 #include <gl\glu.h>

   //
   //#include "DibujoLineas.cpp"
 class Linea
 {
        private:
                PuntoV2F* origen;             //PuntoV2F origen
                PuntoV2F* destino;            //PuntoV2F destino

                //Funciones de implementaci�n interna del recorte
                bool CS(PuntoV2F* p1, PuntoV2F* p2, PuntoV2F* ii, PuntoV2F* sd);
                GLbyte codigoCS(PuntoV2F* punto, PuntoV2F* ii, PuntoV2F* sd);
                void recortarDer(PuntoV2F*& p1, PuntoV2F* p2, PuntoV2F* sd);
                void recortarIzq(PuntoV2F*& p1, PuntoV2F* p2, PuntoV2F* ii);
                void recortarSup(PuntoV2F*& p1, PuntoV2F* p2, PuntoV2F* sd);
                void recortarInf(PuntoV2F*& p1, PuntoV2F* p2, PuntoV2F* ii);

        public:
                Linea();
                Linea(Linea* linea);
                Linea(PuntoV2F* puntoOrigen, PuntoV2F* puntoDestino);
                ~Linea();
                void setOrigen(PuntoV2F* punto);
                PuntoV2F* getOrigen();
                void setDestino(PuntoV2F* punto);
                PuntoV2F* getDestino();
                void draw();
                bool recorte(PuntoV2F* puntoA, PuntoV2F* puntoB);
                bool estaPuntoV2FVertices(PuntoV2F* punto);
                bool estaPuntoV2FIzq(PuntoV2F* punto);
                void girar(PuntoV2F* centro, float ang);
                void mover(PuntoV2F* desplazamiento);
                void buscarInfIzqYSupDer(PuntoV2F*& sd,PuntoV2F*& ii);
                void dibujaCortado();
                void fractalizaK1(DibujoLineas *  nuevaLista);

                float calculoAngulo(PuntoV2F A, PuntoV2F B)  ;
                //void fractalizaK1(DibujoLineas* d);
 };

//---------------------------------------------------------------------------

 #endif