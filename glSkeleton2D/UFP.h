//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Anidar1;
        TMenuItem *Acercar1;
        TMenuItem *Alejar1;
        TMenuItem *Trasladar1;
        TMenuItem *Centrar1;
        TMenuItem *Tilling1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
    void __fastcall Tilling1Click(TObject *Sender);
    void __fastcall Acercar1Click(TObject *Sender);
    void __fastcall Alejar1Click(TObject *Sender);
    void __fastcall Trasladar1Click(TObject *Sender);
    void __fastcall Centrar1Click(TObject *Sender);
    void __fastcall Anidar1Click(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tama�o del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 // m�todos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();
 //Variables globales
    int nTriangulos;   //N�mero de tri�ngulos
    bool mEmbaldosado; //Indica si est� en modo embaldosado
    bool mDesplazar;   //Indica si est� en modo desplazar
    int nCol;          //N�mero de columnas para el embaldosado
    int nFil;          //N�mero de filas para el embaldosado
    GLint x1,x2,x3,y1,y2,y3;    //Coordenadas de los v�rtices del �ltimo triangulo
                                //dibujado
 //Funciones
    void dibujarMotivo();
    void pintarConBaldosas();
    void pintarSinBaldosas();
    void zoom(int porcentaje);  
    void calculaMedias();
    void dibujaTriangulo();
    
 public:		// User declarations
   __fastcall TGLForm2D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
