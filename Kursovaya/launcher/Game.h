//---------------------------------------------------------------------------

#ifndef GameH
#define GameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall StaticText1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StaticText2Click(TObject *Sender);
	void __fastcall StaticText3Click(TObject *Sender);
	void __fastcall StaticText4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
