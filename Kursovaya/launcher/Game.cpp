//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "Game.h"
#include "GameAuthors.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image2Click(TObject *Sender)
{
   //	Form5->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image4Click(TObject *Sender)
{
	//StaticText1->Visible = true;
	//StaticText2->Visible = true;
	//StaticText3->Visible = true;
	//StaticText4->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Image3Click(TObject *Sender)
{
	//Form4->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
	//StaticText1->Visible = false;
	//StaticText2->Visible = false;
	//StaticText3->Visible = false;
	//StaticText4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::StaticText1Click(TObject *Sender)
{
//FormCreate(Sender);
//Form6->Show();

}
//---------------------------------------------------------------------------


void __fastcall TForm4::StaticText2Click(TObject *Sender)
{
//FormCreate(Sender);
//WinExec("MineSweeper1.exe",10);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::StaticText3Click(TObject *Sender)
{
//FormCreate(Sender);
//WinExec("Project3.exe",0);

}
//---------------------------------------------------------------------------

void __fastcall TForm4::StaticText4Click(TObject *Sender)
{
//FormCreate(Sender);
//Form7->Show();
}
//---------------------------------------------------------------------------

