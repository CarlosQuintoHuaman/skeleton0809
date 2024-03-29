//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

Escena::Escena()
{
    dibujos = new Lista<DibujoLineas>();
    xRight=200;
    xLeft=-xRight;
    yTop=xRight;
    yBot=-yTop;
}

//---------------------------------------------------------------------------

Escena::~Escena()
{
    if(dibujos != NULL){
        delete dibujos;
        dibujos = NULL;
    }
}


Lista<DibujoLineas>* Escena::getDibujos(){
return dibujos;
}


//---------------------------------------------------------------------------

void Escena::poliEspiral(PuntoV2F *posInicial,double incrAng,double angInicial,double incrLong,double longInicial,int nPasos)
{
  Lapiz *l=new Lapiz(posInicial,angInicial);
  DibujoLineas *nuevoDibujo= new DibujoLineas();
  PuntoV2F *posAct=new PuntoV2F(posInicial);
  for (int i=0;i<nPasos;i++){
        l->avanzar(longInicial,true);
        longInicial+=incrLong;
        l->turn(incrAng);
        Linea *nuevaLinea=new Linea(posAct,l->getPosicion());
        nuevoDibujo->insertaLinea(nuevaLinea);
        delete posAct;
        PuntoV2F* punto = l->getPosicion();
        posAct=new PuntoV2F(punto);
  }
  dibujos->inserta(nuevoDibujo);
  delete l;
  l=NULL;
  delete posAct;
  posAct=NULL;
}

//---------------------------------------------------------------------------

void Escena::dibuja()
{
  DibujoLineas *aux;

  if(dibujos!=NULL && dibujos->getLongitud()>0){
      dibujos->inicia();

      for(int i=0;i<dibujos->getLongitud();i++){
            aux=dibujos->getActual();
            aux->draw();
            dibujos->avanza();
      }
  }
}

//---------------------------------------------------------------------------

void Escena::inserta(DibujoLineas *dibujo)
{
  dibujos->inserta(dibujo);
}

//---------------------------------------------------------------------------

void Escena::seleccion(double x,double y)
{
  bool encontrado=false;
  dibujos->inicia();
  DibujoLineas *actual;
  PuntoV2F* punto = new PuntoV2F(x,y);
  for(int i=0;i<dibujos->getLongitud();i++){
     actual=dibujos->getActual();
     actual->setSeleccionado(false);
     if(!encontrado){
        encontrado=actual->seleccionar(punto);
        if(encontrado) {
            actual->setSeleccionado(true);
        }
     }
     dibujos->avanza();
  }
  delete punto;
  punto = NULL;
}

//---------------------------------------------------------------------------

void Escena::borraDibujo(DibujoLineas *d)
{
   int i=0;
   bool encontrado=false;
   dibujos->inicia();
   DibujoLineas *aux;
   while(i<dibujos->getLongitud() && !encontrado){
      aux=dibujos->getActual();
      if(aux!=d) {
         dibujos->avanza();
         i++;
      }
      else{
         dibujos->eliminaActual();
         encontrado=true;
         for(int j=i;j<dibujos->getLongitud();j++){
            dibujos->avanza();
         }
      }
   }
}

//---------------------------------------------------------------------------

void Escena::enMarca(PuntoV2F* p1,PuntoV2F* p2)
{                    //origen      destino
    wLeft=p1->getX();
    wRight=p2->getX();
    wTop=p1->getY();
    wBot=p2->getY();
    dibuja();
}

//---------------------------------------------------------------------------

bool Escena::recorte(PuntoV2F *orig,PuntoV2F *dest)
{
        bool borrado = true;

  dibujos->inicia();
  for(int i=0;i<dibujos->getLongitud();i++){
     DibujoLineas* d=dibujos->getActual();
     if (!d->recorte(orig,dest))
        dibujos->eliminaActual();
     else
     dibujos->avanza();
  }

  if ((dibujos->getLongitud()==0)){
                borrado = false;
        }


  return borrado;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)

