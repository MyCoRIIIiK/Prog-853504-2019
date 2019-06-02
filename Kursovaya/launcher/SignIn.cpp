//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SignIn.h"
#include <string.h>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

AnsiString NickName;
AnsiString Login;
AnsiString Password;
bool isGood = false;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{

}








void __fastcall TForm3::Image2Click(TObject *Sender)
{
	Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3Click(TObject *Sender)
{
	if(isGood == true)
	{
		FILE *f;
		AnsiString a;
		f = fopen("Save Password.txt","w");
		ofstream fout ("Save Password.txt");
		a = Edit1->Text;
		fout << a << "\n";
		a = Edit2->Text;
		fout << a << "\n";
		a = Edit3->Text;
		fout << a << "\n";
		fclose(f);
		Form3->Close();
		ShowMessage("You have successfully registered");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	if(Edit3->Text != "")
	{
		if(Edit3->Text == Edit4->Text)
		{
			isGood = true;
			Image4->Visible = false;
			Image6->Visible = true;
		}
		else
		{
			Image4->Visible = true;
			Image6->Visible = false;
			isGood = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3Change(TObject *Sender)
{
	Edit4->Visible = true;
	Image4->Visible = true;

	if(Edit3->Text != 0)
	{
		Image5->Visible = true;
	}
	else
	{
		Image5->Visible = false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormCreate(TObject *Sender)
{
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
	Image4->Visible = false;
	Image5->Visible = false;
    Image6->Visible = false;
}
//---------------------------------------------------------------------------

