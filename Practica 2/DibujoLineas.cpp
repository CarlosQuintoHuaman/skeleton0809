//---------------------------------------------------------------------------

 #include <vcl.h>
 #pragma hdrstop
 #include "DibujoLineas.h"

//---------------------------------------------------------------------------

 DibujoLineas::DibujoLineas()
 {
        segmentos = new Lista<Linea>;
        seleccionado = false;
 }

//---------------------------------------------------------------------------

 DibujoLineas::DibujoLineas(DibujoLineas* dL)
 {
        segmentos = new Lista<Linea>;
        dL->segmentos->inicia();
        for (int i=0;i<dL->segmentos->getLongitud();i++)
        {
                Linea* linea = new Linea(dL->segmentos->getActual());
                segmentos->inserta(linea);
                dL->segmentos->avanza();
        }
        seleccionado = false;
 }

//---------------------------------------------------------------------------

 DibujoLineas::DibujoLineas(PuntoV2F* p, int numIteraciones,int longIni,int incrLado,int incrAng)
 {
        segmentos = new Lista<Linea>;
        PuntoV2F* pun = new PuntoV2F(p);
        Lapiz* lapiz = new Lapiz(pun, 0);
        for(int i=1;i<=numIteraciones;i++){
                PuntoV2F* z = lapiz->getPosicion();
                PuntoV2F* a = new PuntoV2F(z);
                lapiz->avanzar(longIni,false);
                z = lapiz->getPosicion();
                PuntoV2F* b = new PuntoV2F(z);
                lapiz->turn(incrAng);
                longIni+=incrLado;
                Linea* linea = new Linea(a,b);
                segmentos->inserta(linea);
        }
        delete lapiz;
        seleccionado = false;
 }

//---------------------------------------------------------------------------

 DibujoLineas::DibujoLineas(PuntoV2F* centro,int nLados,int lado)
 {
        segmentos = new Lista<Linea>;
        double alfa = 360.0/(double)nLados;
        double radio = (double)lado / (double)sin((alfa*3.1415926535)/180.0);

        PuntoV2F* origen = new PuntoV2F(centro->getX()+radio,centro->getY());
        Lapiz* lapiz = new Lapiz(origen,0);

        for (int i=1;i<=nLados;i++){
                PuntoV2F* z = lapiz->getPosicion();
                PuntoV2F* a = new PuntoV2F(z);
                //Calculamos el punto
                PuntoV2F* punto = new PuntoV2F(
                  centro->getX()+radio*cos((i*alfa*3.1415926535)/180.0),
                  centro->getY()+radio*sin((i*alfa*3.1415926535)/180.0));
                //Trazamos linea hasta punto
                lapiz->lineTo(punto);
                z = lapiz->getPosicion();
                PuntoV2F* b = new PuntoV2F(z);
                Linea* linea = new Linea(a,b);
                insertaLinea(linea); 
        }
        delete lapiz;
        seleccionado = false;
 }

//---------------------------------------------------------------------------

 DibujoLineas::~DibujoLineas()
 {
        if (segmentos!=NULL){
                delete segmentos;
        }
 }

//---------------------------------------------------------------------------

 void DibujoLineas::insertaLinea(Linea* linea)
 {
         segmentos->inserta(linea);
 }

//---------------------------------------------------------------------------

 void DibujoLineas::draw()
 {
    Linea* linea;
    segmentos->inicia();
    for (int i=0;i<segmentos->getLongitud();i++){
        linea = segmentos->getActual();
        if(seleccionado){ // si esta selecionado hay que pintar los puntos
            glPointSize(5);
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
                glVertex2f((GLdouble)linea->getOrigen()->getX(),(GLdouble)linea->getOrigen()->getY());
                glVertex2f((GLdouble)linea->getDestino()->getX(),(GLdouble)linea->getDestino()->getY());
            glEnd();
            glColor3f(1,1,1);
        }
        linea->draw();        
        segmentos->avanza();
    }
 }
 
//---------------------------------------------------------------------------

 bool DibujoLineas::recorte(PuntoV2F* puntoA, PuntoV2F* puntoB)
 {
        bool borrado = true;
        segmentos->inicia();
        int longitud = segmentos->getLongitud();
        for (int i=0;i<longitud;i++){
                Linea* linea = segmentos->getActual();
                if(!linea->recorte(puntoA, puntoB)){

                    segmentos->eliminaActual();
                }else{
                    segmentos->avanza();
                }
        }
        if (segmentos->getLongitud()==0){
                borrado = false;
        }        else borrado = true;
        return borrado;
 }
//---------------------------------------------------------------------------

 void DibujoLineas::recorte(double wLeft,double wRight,double wTop,double wBot)
 {
   segmentos->inicia();
   int j=segmentos->getLongitud();
   for(int i=0;i<j;i++){
      Linea* linea=new Linea(segmentos->getActual());
      segmentos->eliminaActual();
      PuntoV2F* ii = new PuntoV2F(wLeft,wBot);
      PuntoV2F* sd = new PuntoV2F(wRight,wTop);
      if (linea->recorte(ii,sd)){ //si devuelve  true se vuelve a meter en la lista
          segmentos->inserta(linea);
      }
      else{
        delete linea;
        linea = NULL;
   }
}}

//---------------------------------------------------------------------------

 bool DibujoLineas::seleccionar(PuntoV2F* punto)
 {
        segmentos->inicia();
        int i = 0;
        bool encontrado = false;
        seleccionado = false;
        while ((i<segmentos->getLongitud())&&(!encontrado)){
                Linea* linea = segmentos->getActual();
                if(linea->estaPuntoV2FVertices(punto)){
                        encontrado = true;
                        seleccionado = true;
                }
                segmentos->avanza();
                i++;
        }
        return encontrado;
 }

//---------------------------------------------------------------------------

 bool DibujoLineas::getSeleccionado()
 {
        return seleccionado;
 }

//---------------------------------------------------------------------------

 void DibujoLineas::setSeleccionado(bool selec)
 {
        seleccionado = selec;
 }

//---------------------------------------------------------------------------

 bool DibujoLineas::estaPuntoV2FDentro(PuntoV2F* punto)
 {
        segmentos->inicia();
        int i = 0;
        bool dentro = true;
        while ((i<segmentos->getLongitud())&&(dentro)){
                Linea* linea = segmentos->getActual();
                if(!linea->estaPuntoV2FIzq(punto))
                {
                        dentro = false;
                }

                segmentos->avanza();
                i++;
        }
        return dentro;
 }

//---------------------------------------------------------------------------

 Lista<Linea>* DibujoLineas::getSegmentos()
 {
        return segmentos;
 }

//---------------------------------------------------------------------------

 void DibujoLineas::girarConCentro(PuntoV2F* centro,double ang)
 {
        Lista<Linea>* seg = getSegmentos();
        seg->inicia();
        for (int i=0;i<seg->getLongitud();i++){
                Linea* linea = seg->getActual();
                linea->girar(centro,ang);
                seg->avanza();
        }
 }

//---------------------------------------------------------------------------

 void DibujoLineas::mover(PuntoV2F* desplazamiento)
 {
        segmentos->inicia();
        for (int i=0;i<segmentos->getLongitud();i++){
                Linea* linea = segmentos->getActual();
                linea->mover(desplazamiento);
                segmentos->avanza();
        }
 }

//---------------------------------------------------------------------------

 bool DibujoLineas::vacia(){
    if (segmentos==NULL){
        return true;
    }
    else{
        return segmentos->vacia();
    }
 }
//---------------------------------------------------------------------------
 #pragma package(smart_init)
