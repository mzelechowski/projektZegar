//---------------------------------------------------------------------------

#ifndef zegarH
#define zegarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Mask.hpp>
#include <MPlayer.hpp>
#include <ImgList.hpp>
#include <FileCtrl.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp> ///biblioteka do Mplayer1
//---------------------------------------------------------------------------
class TfZegarek : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *Timer1;
        TBitBtn *BitBtn1;
        TButton *bPazua;
        TLabel *Label1;
        TLabel *Label2;
        TMaskEdit *meMM;
        TMaskEdit *meSS;
        TMaskEdit *meHH;
        TBitBtn *bMMplus;
        TBitBtn *bMMminus;
        TBitBtn *bSSplus;
        TBitBtn *bHHplus;
        TBitBtn *bHHminus;
        TBitBtn *bSSminus;
        TButton *bNastaw;
        TButton *bGraj;
        TButton *bTik;
        TMediaPlayer *MediaPlayer1;
        TButton *bAGraj;
        TMaskEdit *meAG;
        TLabel *lNastawnik;
        TLabel *Label3;
        TButton *bAbout;
        TImage *Image2;
        TEdit *Edit1;
        TButton *bSlajdShowStart;
        TOpenPictureDialog *OpenPictureDialog1;
        TButton *bSlajdShowStop;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall bPazuaClick(TObject *Sender);
        void __fastcall bMMplusClick(TObject *Sender);
        void __fastcall rysuj();
        void __fastcall nastaw();
        void __fastcall bMMminusClick(TObject *Sender);
        void __fastcall bHHplusClick(TObject *Sender);
        void __fastcall bHHminusClick(TObject *Sender);
        void __fastcall bSSplusClick(TObject *Sender);
        void __fastcall bSSminusClick(TObject *Sender);
        void __fastcall bNastawClick(TObject *Sender);
        void __fastcall bGrajClick(TObject *Sender);
        void __fastcall bTikClick(TObject *Sender);
        void __fastcall MediaPlayer1Notify(TObject *Sender);
        void __fastcall bAGrajClick(TObject *Sender);
        void __fastcall bAboutClick(TObject *Sender);
        void __fastcall bSlajdShowStartClick(TObject *Sender);
        void __fastcall bSlajdShowStopClick(TObject *Sender);


private:	// User declarations
        double SdeltaX, MdeltaX, HdeltaX;
        double SdeltaY, MdeltaY, HdeltaY;
        double Skat, Mkat, Hkat;
        double Sx, Mx, Hx;
        double Sy, My, Hy;
        int Mmnoz, Smnoz, Hmnoz;
        int przel;
        String Zczas;
        int licz_slajd, odliczanie;
        AnsiString resultFile, resultPath;
        //int minuta;

public:		// User declarations
        __fastcall TfZegarek(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TfZegarek *fZegarek;
//---------------------------------------------------------------------------
#endif
