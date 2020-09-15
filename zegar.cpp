//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
//#include <systdate.h>
#include <mmsystem.h>  ////// bibioteka do sndPlaySound
#pragma hdrstop
#include "zegar.h"
#include "witaj.h"

#include <shfolder.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <new>
#include <windows.h>




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfZegarek *fZegarek;
//---------------------------------------------------------------------------
__fastcall TfZegarek::TfZegarek(TComponent* Owner)
        : TForm(Owner)
{
        DoubleBuffered = true;
        nastaw();
        TfWitaj* fWitaj=new TfWitaj(this);
        fWitaj->ShowModal();
        delete fWitaj;
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::BitBtn1Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::Timer1Timer(TObject *Sender)
{
        int i;
        Smnoz++;
        if(bTik->Caption=="Tik ON")
        {
                sndPlaySound("tik.wav", SND_ASYNC );
        }
        rysuj();
/////////////////////////////////////////////////
        if(bAGraj->Caption=="AutoGraj ON")
        {
                if(TryStrToInt(meAG->Text,i))
                {
                        if((StrToInt(meAG->Text)>0)&&(StrToInt(meAG->Text)<59))
                        {
                                TDateTime Nastawnik=StrToTime(Zczas)+StrToTime("00:"+meAG->Text+":00");
                                TDateTime Czas=StrToTime(IntToStr(Hmnoz)+":"+IntToStr(Mmnoz)+":"+IntToStr(Smnoz));
                                lNastawnik->Caption=Nastawnik;

                                if(Czas==Nastawnik)
                                {
                                        Zczas=IntToStr(Hmnoz)+":"+IntToStr(Mmnoz)+":"+IntToStr(Smnoz);
                                        bGrajClick(bGraj);  //wywolanie funkcji graj
                                }
                        }
                }
                else
                {
                        lNastawnik->Caption="WprowadŸ liczbe";
                }
        }
///////////////////////////////////////////////////////Pokaz slajdow
//if (licz_slajd==0)
//{
//        licz_slajd=2470;
//}
String b;
odliczanie++;
if(odliczanie==3)
{

 if(IntToStr(licz_slajd).Length()==1)
{
        b="000"+IntToStr(licz_slajd);
} else if(IntToStr(licz_slajd).Length()==2)
{
        b="00"+IntToStr(licz_slajd);
} else if(IntToStr(licz_slajd).Length()==3)
{
        b="0"+IntToStr(licz_slajd);
} else
{
        b=IntToStr(licz_slajd);
}


        b=resultPath+"DSC_"+b+".jpg";
        if ( FileExists(b)==true )
        {
                Edit1->Text =b;
                Image2->Picture->LoadFromFile(b);
        }
        licz_slajd++;
        odliczanie=0;
}
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bPazuaClick(TObject *Sender)
{
           if(Timer1->Enabled==true)
                Timer1->Enabled=false;
           else
                Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::rysuj()
{
Sx=0;
Sy=360;
Mx=0;
My=340;
Hx=0;
Hy=265;
        if (Smnoz>59)
        {
                Smnoz=0;
                Mmnoz++;
        }
        if (Smnoz<0)
        {
                Smnoz=59;
                Mmnoz--;
        }

        if (Mmnoz<0)
        {
                Mmnoz=59;
                Hmnoz--;
        }
        if (Mmnoz>59)
        {
                Mmnoz=0;
                Hmnoz++;
        }
        if (Hmnoz<0){Hmnoz=23;}
        if (Hmnoz>=24){Hmnoz=0;}
        
        Skat=6*Smnoz;
        Mkat=6*Mmnoz+6*Smnoz/60*0;  //////////// *0 przeskok wskazowki minutowej
        Hkat=30*Hmnoz+30*Mmnoz/60;
        SdeltaX=cos(Skat*M_PI/180)*Sx+sin(Skat*M_PI/180)*Sy;
        SdeltaY=cos(Skat*M_PI/180)*Sy-sin(Skat*M_PI/180)*Sx;
        MdeltaX=cos(Mkat*M_PI/180)*Mx+sin(Mkat*M_PI/180)*My;
        MdeltaY=cos(Mkat*M_PI/180)*My-sin(Mkat*M_PI/180)*Mx;
        HdeltaX=cos(Hkat*M_PI/180)*Hx+sin(Hkat*M_PI/180)*Hy;
        HdeltaY=cos(Hkat*M_PI/180)*Hy-sin(Hkat*M_PI/180)*Hx;
        meHH->Text=Hmnoz;
        meMM->Text=Mmnoz;
        meSS->Text=Smnoz;

fZegarek->Refresh();
Canvas->Pen->Style = psSolid;
        Canvas->Pen->Width = 18;
        Canvas->Pen->Color = clBlack;
        Canvas->MoveTo(400, 400);
        Canvas->LineTo(400+HdeltaX, 400-HdeltaY);
                Canvas->Pen->Width = 12;
                Canvas->Pen->Color = clBlue;
                Canvas->MoveTo(400, 400);
                Canvas->LineTo(400+MdeltaX, 400-MdeltaY);
        Canvas->Pen->Width = 6;
        Canvas->Pen->Color = clRed;
        Canvas->MoveTo(400, 400);
        Canvas->LineTo(400+SdeltaX, 400-SdeltaY);
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::nastaw()
{
        TDateTime czas = TDateTime::CurrentDateTime();
        WORD godzina, minuta, sekunda, milisekunda;
        czas.DecodeTime(&godzina, &minuta, &sekunda, &milisekunda);
        Hmnoz= godzina;
        Mmnoz= minuta;
        Smnoz= sekunda;
        //Label4->Caption = milisekunda;// prawidlowy zapis = IntToStr(milisekunda);
        //Now();
        //bNastaw->Caption=HourOf(Time());
       // bNastaw->Caption=TimeToStr(Now());
       //
        rysuj();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bMMplusClick(TObject *Sender)
{
        Mmnoz++;
        rysuj();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bMMminusClick(TObject *Sender)
{
        Mmnoz--;
        rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TfZegarek::bHHplusClick(TObject *Sender)
{
        Hmnoz++;
        rysuj();
}
//---------------------------------------------------------------------------

void __fastcall TfZegarek::bHHminusClick(TObject *Sender)
{
        Hmnoz--;
        rysuj();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bSSplusClick(TObject *Sender)
{
        Smnoz++;
        rysuj();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bSSminusClick(TObject *Sender)
{
        Smnoz--;
        rysuj();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bNastawClick(TObject *Sender)
{
        nastaw();
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bGrajClick(TObject *Sender)
{

        TStrings *PlayList = new TStringList;
        String h="WAV\\h"+IntToStr(Hmnoz)+".wav";
        PlayList->Add(h);
        String m="WAV\\m"+IntToStr(Mmnoz)+".wav";
        PlayList->Add(m);

         Application->ProcessMessages( );
        if ( FileExists(h)==true )
        {
                MediaPlayer1->FileName=PlayList->Strings[0];
                MediaPlayer1->Open();
        //      MediaPlayer1->Wait = true;
                MediaPlayer1->Play();
                bGraj->Enabled=false;
                przel=1;
        }
         //       MediaPlayer1->Wait = false;
       /* MediaPlayer1->FileName=PlayList->Strings[1];
        MediaPlayer1->Open();
        MediaPlayer1->Play();

        /*
        if ( FileExists(h)==true )
        {
                MediaPlayer1->FileName=h;
                MediaPlayer1->Open();
                MediaPlayer1->Play();
        }
        //String m="WAV\\m"+IntToStr(Mmnoz)+".wav";
       if ( FileExists(m)==true )
        {
                MediaPlayer1->FileName=m;
                MediaPlayer1->Open();
                MediaPlayer1->Play();
        }         */
}
//--------------------------------------------------------------------------
void __fastcall TfZegarek::MediaPlayer1Notify(TObject *Sender)
{
        if( przel)
        {
                String m="WAV\\m"+IntToStr(Mmnoz)+".wav";
                if ( FileExists(m)==true )
                {
                        MediaPlayer1->FileName=m;
                        MediaPlayer1->Open();
                        MediaPlayer1->Play();
                }
                przel=0;
                bGraj->Enabled=true;
        }
        else
        {
         MediaPlayer1->Close();
         przel=1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bTikClick(TObject *Sender)
{
        if(bTik->Caption=="Tik OFF")
        {
                bTik->Caption="Tik ON";
        }
        else
        {
                bTik->Caption="Tik OFF";
        }
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bAGrajClick(TObject *Sender)
{

        if(bAGraj->Caption=="AutoGraj ON")
        {
                bAGraj->Caption="AutoGraj OFF";
                lNastawnik->Caption="--:--:--";
        }
        else
        {
                bAGraj->Caption="AutoGraj ON";
                Zczas=IntToStr(Hmnoz)+":"+IntToStr(Mmnoz)+":00";
                //Zczas=meHH->Text+":"+IntToStr(Mmnoz)+":00";
                //+IntToStr(Smnoz);

        }
}
//---------------------------------------------------------------------------


void __fastcall TfZegarek::bAboutClick(TObject *Sender)
{
        TfWitaj* fWitaj=new TfWitaj(this);
        fWitaj->ShowModal();
        delete fWitaj;        
}
//---------------------------------------------------------------------------


void __fastcall TfZegarek::bSlajdShowStartClick(TObject *Sender)
{
        //AnsiString Caption = "Select a Directory";

        //AnsiString Directory = "C:";
        //const WideString Root = "C:\"";
        //    SelectDirectory(Caption, Root, Directory);

             //SelectDirectory(Directory, TSelectDirOpts(), 0);
        //Edit1->Text = Directory ;
        //AnsiString fileName = "C:";
         //result = GetFileName();
        OpenPictureDialog1->Execute();
        resultFile=OpenPictureDialog1->FileName;
        Edit1->Text =resultFile;
        resultFile=ExtractFileName(resultFile);
        resultPath=ExtractFilePath(OpenPictureDialog1->FileName);
        resultFile.Delete(1, 4);
        licz_slajd=StrToInt(resultFile.Delete(resultFile.Length()-3,4));
}
//---------------------------------------------------------------------------
void __fastcall TfZegarek::bSlajdShowStopClick(TObject *Sender)
{
        licz_slajd=0;
}
//---------------------------------------------------------------------------

