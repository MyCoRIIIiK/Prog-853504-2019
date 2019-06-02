//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SignUp.h"
#include "Game.h"
#include "SignIn.h"
#include "fstream"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image4Click(TObject *Sender)
{
	bool inccorectEnterPassword = true,inccorectEnterLogin = true;

	char a[50];

	ifstream fin ("Save Password.txt");

	if(fin.is_open())
	{
		while(!fin.eof())
		{
			fin >> a;//пропускаем никнейм

			if(Edit2->Text == a)
			{
				inccorectEnterLogin = false;
			}

			fin >> a;

			if(Edit3->Text == a)
			{
				inccorectEnterPassword = false;
			}
	   }
	}
	fin.close();

	if(inccorectEnterPassword == true)
	{
		ShowMessage("Invalid password, check the data entered");
	}

	if(inccorectEnterLogin == true)
	{
		ShowMessage("Invalid username, check the data entered");

	}

	if(inccorectEnterLogin == false && inccorectEnterPassword == false)
	{
		ShowMessage("You entered!");
		Form2->Close();
		Form3->Close();
		Form4->Show();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2Click(TObject *Sender)
{
	Form2->Close();
    Edit2->Text = "";
	Edit3->Text = "";
}
//---------------------------------------------------------------------------


