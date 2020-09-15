//---------------------------------------------------------------------------

#ifndef witajH
#define witajH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfWitaj : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *Image2;
        TLabel *Label1;
        TTimer *TimerWitaj;
        TButton *bWZamknij;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall TimerWitajTimer(TObject *Sender);
        void __fastcall bWZamknijClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfWitaj(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfWitaj *fWitaj;
//---------------------------------------------------------------------------
#endif
