//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WindowToLogin.h"
#include "SignIn.h"
#include "SignUp.h"
#include "Game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image3Click(TObject *Sender)
{
	Form2->Close();
	Form3->Show();
	Form3->Top = Form1->Top + 34;
	Form3->Left = Form1->Left + 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
	Form3->Close();
	Form2->Show();
	Form2->Top = Form1->Top + 34;
	Form2->Left = Form1->Left + 10;
}
//---------------------------------------------------------------------------


