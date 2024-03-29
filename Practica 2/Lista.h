//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH

#include "Nodo.h"
//---------------------------------------------------------------------------
template <class T> class Lista{
private:
   Nodo<T>* primero;
   Nodo<T>* actual;
   int longitud;

public:
   Lista();
   ~Lista();
   void inicia();
   void avanza();
   T* getActual();
   bool vacia();
   bool final();
   void inserta(T*);
   void eliminaActual();
   int getLongitud();
};

template <class T> Lista<T>::Lista(){
  primero=NULL;
  actual=NULL;
  longitud= 0;
}
template <class T> Lista<T>::~Lista(){
  Nodo<T>* r= primero;
  Nodo<T>* aux;
  while(r!=NULL){
    aux= r->getSig();
    delete r;
    r= aux;
  }
}
template <class T> void Lista<T>::inicia(){
  actual=primero;
}
template <class T> T* Lista<T>::getActual(){
  if(actual==NULL) return NULL;
  else return actual->getInf();
}
template <class T> void Lista<T>::avanza(){
  if(actual!=NULL) actual= actual->getSig();

}
template <class T> bool Lista<T>::vacia(){
  return primero==NULL;
}
template <class T> bool Lista<T>::final(){
  return actual==NULL;
}
template <class T> void Lista<T>::inserta(T* t){
  if(vacia()){
    primero= new Nodo<T>(t, NULL, NULL);
    actual=primero;
  }
  else{
    Nodo<T>* aux= primero;
    primero= new Nodo<T>(t, aux, NULL);
    aux->setAnt(primero);
  }
  longitud++;
}
template <class T> void Lista<T>::eliminaActual(){
  if(actual!=NULL){
    if(actual->getSig()!=NULL)
       actual->getSig()->setAnt(actual->getAnt());
    if(actual->getAnt()!=NULL)
       actual->getAnt()->setSig(actual->getSig());

    if(actual==primero) primero= primero->getSig();
    Nodo<T>* aux= actual->getSig();
    delete actual;
    actual= aux;
    longitud--;
  }
}
template <class T> int Lista<T>::getLongitud(){
  return longitud;
}
#endif
