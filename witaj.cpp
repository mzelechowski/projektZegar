//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "witaj.h"
#include "zegar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfWitaj *fWitaj;
//---------------------------------------------------------------------------
__fastcall TfWitaj::TfWitaj(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfWitaj::FormShow(TObject *Sender)
{
        Label1->Caption="Zegar edukacyjny dla Ani i Piotrusia.";
        Label2->Caption="2011.10. Wersja 1.0";
        Label3->Caption="autor: Maciej ¯elechowski";
        Label4->Caption="email: mzelechowski@interia.pl";
        TimerWitaj->Interval =10000;
        TimerWitaj->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfWitaj::TimerWitajTimer(TObject *Sender)
{
        TimerWitaj->Enabled=false;
        Close();

}
//---------------------------------------------------------------------------

void __fastcall TfWitaj::bWZamknijClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

