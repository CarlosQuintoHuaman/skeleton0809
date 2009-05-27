//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Color.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

Color::Color(){
    azul = 0;
    rojo = 0;
    verde = 0;
}

//---------------------------------------------------------------------------

Color::Color(Color* c){
    azul = c->azul;
    rojo = c->rojo;
    verde = c->verde;
}

//---------------------------------------------------------------------------

Color::Color(float blue, float red, float green){
    azul = blue;
    rojo = red;
    verde = green;
}

//---------------------------------------------------------------------------

float Color::getAzul() {
    return azul;
}

//---------------------------------------------------------------------------

float Color::getVerde() {
  return verde;
}

//---------------------------------------------------------------------------

float Color::getRojo() {
  return rojo;
}

//---------------------------------------------------------------------------

void Color::setAzul(float blue){
    azul = blue;
}

//---------------------------------------------------------------------------

void Color::setVerde(float green){
    verde = green;
}

//---------------------------------------------------------------------------

void Color::setRojo(float red){
    rojo = red;
}

//---------------------------------------------------------------------------
